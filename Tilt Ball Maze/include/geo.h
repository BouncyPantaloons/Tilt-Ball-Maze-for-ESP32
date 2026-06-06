#include <Arduino.h>
#include <vector>
#include <iostream>

struct Vector3 
{
    Vector3() {}
    Vector3(float x, float y, float z) 
    {
        Vector3::x = x;
        Vector3::y = y;
        Vector3::z = z;
    }

    float x;
    float y;
    float z;
};

struct Vector2
{
    Vector2() {}
    Vector2(float x, float y) { Vector2::x = x; Vector2::y = y; }

	float x;
	float y;

    inline float Magnitude()
	{
        return sqrt(x * x + y * y);
	}

    inline float SqrMagnitude()
	{
        return x * x + y * y;
	}

	inline void operator+=(Vector2 v)
	{
		x += v.x;
		y += v.y;
	}

	inline Vector2 operator*(float t)
	{
		return { x * t, y * t };
	}

	inline Vector2 operator/(float t)
	{
		return { x / t , y / t };
	}

	inline Vector2 Normalize()
	{
		float magnitude = Magnitude();
		return { x / magnitude, y / magnitude };
	}

	static inline float Dot(const Vector2& v1, const Vector2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	static inline Vector2 Lerp(const Vector2& v1, const Vector2& v2, const float t)
	{
		return {v1.x + (v2.x - v1.x) * t, v1.y + (v2.y - v1.y) * t};
	}
};

inline Vector2 operator-(Vector2 lhs, Vector2 rhs)
{
    Vector2 result = { lhs.x - rhs.x, lhs.y - rhs.y };
    return result;
}

inline Vector2 operator+(Vector2 lhs, Vector2 rhs)
{
    Vector2 result = { lhs.x + rhs.x, lhs.y + rhs.y };
    return result;
}

static Vector2 up = { 0, 1 };
static Vector2 down = { 0, -1 };
static Vector2 left = { -1, 0 };
static Vector2 right = { 1, 0 };


struct Particle
{
	Vector2 position;
	Vector2 velocity;
};

struct Edge
{
	Vector2 p1;
	Vector2 p2;

	Vector2 GetClosestPointOnEdge(Vector2& point)
	{
		float t = Vector2::Dot(point - p1, p2 - p1) / Vector2::Dot(p2 - p1, p2 - p1);
		t = constrain(t, 0.0, 1.0);
		return (p1 + (p2 - p1) * t);
	}
};

class Shape
{
public:	
	Shape();
	Shape(std::vector<Vector2> vertecies, bool closeShape);
	Shape(std::vector<Vector2> vertecies, bool closeShape, bool fillShape);

	Edge GetClosestEdgeOfShape(Vector2& point);
	Vector2 GetClosestPointOnShape(Vector2& point);
	Vector2 GetClosestVertex(Vector2& point, int& index);
	int& AddVertexToShape(Vector2& point);
	void SetVertextPosition(int index, Vector2& point);

	std::vector<Vector2> vertices;
	bool closeShape;
	bool fillShape;
private:
	Edge GetClosestEdgeOfShapeInternal(Vector2& point, int& p1Index);
};

Shape::Shape()
{
	closeShape = true;
	vertices = std::vector<Vector2>(4);
	vertices[0] = { 0, 0 };
	vertices[1] = { 10, 0 };
	vertices[2] = { 10, 10 };
	vertices[3] = { 0, 10 };
}

Shape::Shape(std::vector<Vector2> vertecies, bool closeShape)
{
	Shape::closeShape = closeShape;
	vertices = vertecies;
    Shape::fillShape = false;
}

Shape::Shape(std::vector<Vector2> vertecies, bool closeShape, bool fillShape)
{
	Shape::closeShape = closeShape;
	Shape::fillShape = fillShape;
	vertices = vertecies;
}

Edge Shape::GetClosestEdgeOfShape(Vector2& point)
{
	int i;
	return GetClosestEdgeOfShapeInternal(point, i);
}

Vector2 Shape::GetClosestPointOnShape(Vector2& point)
{
	std::vector<Vector2> edgePoints = std::vector<Vector2>(vertices.size() - (closeShape ? 0 : 1), { 0, 0 });

	for (int i = 0; i < vertices.size(); i++)
	{
		if (!closeShape && i == vertices.size() - 1) { break; }

		Vector2 p1 = vertices[i];
		Vector2 p2 = vertices[(i + 1) % vertices.size()];

		float t = Vector2::Dot(point - p1, p2 - p1) / Vector2::Dot(p2 - p1, p2 - p1);
		t = constrain(t, 0.0, 1.0);
		edgePoints[i] = p1 + (p2 - p1) * t;
	}

	float closestDistance = std::numeric_limits<float>::max();;
	int closestPointIndex = 0;
	for (int i = 0; i < edgePoints.size(); i++)
	{
		float distance = (edgePoints[i] - point).SqrMagnitude();
		if (distance < closestDistance)
		{
			closestDistance = distance;
			closestPointIndex = i;
		}
	}

	return edgePoints[closestPointIndex];
}

Vector2 Shape::GetClosestVertex(Vector2& point, int& vertex) 
{
	float closestDistance = std::numeric_limits<float>::max();;
	int closestVertexIndex = 0;
	for (int i = 0; i < vertices.size(); i++)
	{
		float distance = (vertices[i] - point).SqrMagnitude();
		if (distance < closestDistance) 
		{
			closestDistance = distance;
			closestVertexIndex = i;
		}
	}
	vertex = closestVertexIndex;
	return vertices[closestVertexIndex];
}

int& Shape::AddVertexToShape(Vector2& point)
{
	int p1Index;
	GetClosestEdgeOfShapeInternal(point, p1Index);

	std::cout << p1Index << std::endl;

	std::vector<Vector2> verts = std::vector<Vector2>(vertices.size() + 1);
	int counter = 0;
	for (int i = 0; i < verts.size(); i++)
	{
		std::cout << i << " " << counter << std::endl;

		if (i == p1Index + 1)
		{
			verts[i] = point;
			continue;
		}
		verts[i] = vertices[counter];
		counter++;
	}

	vertices = std::vector<Vector2>(vertices.size() + 1);
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i] = verts[i];
	}
	return p1Index;
}

void Shape::SetVertextPosition(int index, Vector2& point)
{
	vertices[index] = point;
}

Edge Shape::GetClosestEdgeOfShapeInternal(Vector2& point, int& p1Index)
{
	p1Index = 0;
	Edge closestEdge;
	Vector2 closestPoint;
	float closestDistance = std::numeric_limits<float>::max();

	for (int i = 0; i < vertices.size(); i++)
	{
		if (!closeShape && i == vertices.size() - 1) { break; }

		Vector2 p1 = vertices[i];
		Vector2 p2 = vertices[(i + 1) % vertices.size()];

		float t = Vector2::Dot(point - p1, p2 - p1) / Vector2::Dot(p2 - p1, p2 - p1);
		t = constrain(t, 0.0, 1.0);
		Vector2 edgePoint = p1 + (p2 - p1) * t;

		float distance = (edgePoint - point).SqrMagnitude();
		if (distance < closestDistance)
		{
			closestDistance = distance;
			closestEdge.p1 = p1;
			closestEdge.p2 = p2;
			p1Index = i;
		}
	}

	return closestEdge;
}

struct Hole 
{
    Vector2 position;
    float radius;

    Hole() {} 
    Hole(Vector2 position, float radius) 
    {
        Hole::position = position;
        Hole::radius = radius;
    }
};