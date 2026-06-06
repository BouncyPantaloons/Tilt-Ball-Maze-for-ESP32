#include <Arduino.h>
#include <ctime>
#include <ezButton.h>

#include "FastIMU.h"
#include "data.h"
#include "SPI.h"
#include "TFT_eSPI.h"

#define GYRO_ADDR 0x68
#define SDA_PIN 8
#define SCL_PIN 9
#define BTN_PIN 16
#define RST_CTRL_PIN 10
#define VIB_PIN 18

#define BG_COLOR 0x00a0
#define LINE_COLOR 0x0565
#define PLAYER_COLOR 0xdedb
#define HOLE_COLOR 0x0000
#define HOLE_COLOR2 0x0120
#define HOLE_COLOR3 0x01a0

MPU6050 gyroIMU;
calData calib = { 0 };
GyroData gyroData;
AccelData accelData;
Vector3 accelCalibratedOffset = {0, 0, 0};

TFT_eSPI tft = TFT_eSPI();

ezButton button(BTN_PIN);

const int screenWidth = 240.0;
const int screenHeight = 320.0;

const float collisionDampening = 0.5;
const float friction = 0.995;
const float maxSpeed = 300;
const float acceleration = 4000;
const float ballRadius = 5;

float deltaTime = 0;
float oldTime = 0;
Vector2 tilt = { 0, 0 };

Vector2 goal = { 45, 192 };
bool hasWon = false;
Particle ball = { {50, 50}, {0, 0} };

std::vector<Hole> holes = std::vector<Hole>();
std::vector<Shape> shapes = std::vector<Shape>
{
	Shape(std::vector<Vector2> 
	{
		{1, 1},
		{screenWidth - 1, 1},
		{screenWidth - 1, screenHeight - 1},
		{1, screenHeight - 1},
	}, true),
	Shape(std::vector<Vector2>
	{
		{ 100, 100 },
		{ 200, 100 },
		{ 200, 200 },
		{ 100, 200 },
	}, true),
};

void InitScreen();
void InitGyro();
void CalibrateGyroIMU(int iterations);
void UpdateGyro();

void Simulate(float	deltaTime);
void Edit(float	deltaTime);
void DrawEdges(const std::vector<Edge>& edges, uint32_t color);
inline void DrawEdge(const Edge& edge, uint32_t color);
void DrawShape(const Shape& shape, uint32_t color);
void DrawShapes(const std::vector<Shape>& shapes, uint32_t color);
inline void DrawLine(float x1, float y1, float x2, float y2, uint32_t color);
inline void DrawCircle(float x, float y, float r, uint32_t color);
inline void DrawHoles(const std::vector<Hole>& holes);
inline void DrawHole(const Hole hole);

void setup() {
  shapes = lvlShapes;
  holes = lvlHoles;
  ball.position = startPosition;

  Serial.begin(115200);

  pinMode(VIB_PIN, OUTPUT);

  InitScreen();
  InitGyro();
  oldTime = clock();

  DrawHoles(holes);
	DrawShapes(shapes, LINE_COLOR);
}

void InitScreen() 
{
  tft.init();
  tft.fillScreen(BG_COLOR);
  tft.setTextSize(2);
}

void InitGyro() 
{
  Wire.begin(SDA_PIN,SCL_PIN);
  //gyroIMU.calibrateAccelGyro(&calib);

  int err = gyroIMU.init(calib, GYRO_ADDR);
  if(err != 0)
  {
    Serial.println("IMU Initialization Failed");
    Serial.println(err);
    while(true);
  }

  CalibrateGyroIMU(100);
}

void CalibrateGyroIMU(int iterations) 
{
  accelCalibratedOffset = {0, 0, 0};
  
  for (int i = 0; i < iterations; i++)
  {
    gyroIMU.update();
    gyroIMU.getAccel(&accelData);

    Serial.println(accelData.accelX);

    accelCalibratedOffset.x += accelData.accelX;
    accelCalibratedOffset.y += accelData.accelY;
    accelCalibratedOffset.z += accelData.accelZ;
    delay(5);
  }
  accelCalibratedOffset.x /= iterations;
  accelCalibratedOffset.y /= iterations;
  accelCalibratedOffset.z /= iterations;
}

void loop() {
  UpdateGyro();
  button.loop();

  deltaTime = (clock() - oldTime) / 1000;
  double fps = (1.0 / deltaTime) * 1000;
  oldTime = clock();

  Simulate(deltaTime);
  delay(2);
}

void UpdateGyro() 
{
  gyroIMU.update();
  gyroIMU.getGyro(&gyroData);
  gyroIMU.getAccel(&accelData);
  accelData.accelX -= accelCalibratedOffset.x;
  accelData.accelY -= accelCalibratedOffset.y;
  accelData.accelZ -= accelCalibratedOffset.z;
}


int shapeIndex = 0;
Vector2 previousBallPosition;

int fpsConter = 0;
float prevFPS;
float fpsSum;

float vibrationTimer = 0;
float resetTimer = 0;

Hole fallenHole;
bool isDying = false;
float scale = 1;

float timer = 0;
float prevTimer = 0;
int prevSeconds = 0;
int prevMinutes = 0;

bool hasEdge = false;
Edge e;
bool hasHole = false;
Hole h;

float goalAnimSpeed = 4;
float goalRad = 6;
float curGoalRadAnim = 6;


void Simulate(float deltaTime) 
{
  if (button.getState() == 0) 
  {
    resetTimer = resetTimer + deltaTime;
    if (resetTimer >= 0.5) 
    {
      ESP.restart();
    }
  } 
  else 
  {
    resetTimer = 0;
  }

  if (hasWon) { return; }

  timer += deltaTime;
  int minutes = floor(timer/60.0);
  int seconds = floor(static_cast<int>(timer)%60);
  if (seconds != prevSeconds || minutes != prevMinutes) 
  {
    tft.setRotation(1);
    tft.setTextColor(BG_COLOR);
    tft.drawNumber(prevMinutes, 270, 5);
    tft.drawChar(':', 282, 5);
    if (prevSeconds < 10) 
    {
      tft.drawNumber(0, 294, 5);
      tft.drawNumber(prevSeconds, 306, 5);
    } 
    else 
    {
      tft.drawNumber(prevSeconds, 294, 5);
    }
    
    prevTimer = timer;
    prevMinutes = floor(prevTimer/60.0);
    prevSeconds = floor(static_cast<int>(prevTimer)%60);
  
    tft.setTextColor(LINE_COLOR);
    tft.drawNumber(prevMinutes, 270, 5);
    tft.drawChar(':', 282, 5);
    if (prevSeconds < 10) 
    {
      tft.drawNumber(0, 294, 5);
      tft.drawNumber(prevSeconds, 306, 5);
    } else 
    {
      tft.drawNumber(prevSeconds, 294, 5);
    }
    tft.setRotation(0);
  }


  vibrationTimer -= deltaTime;
  if (vibrationTimer <= 0) 
  {
    analogWrite(VIB_PIN, 0);
  }

  previousBallPosition = ball.position;

  if (isDying) 
  {
    DrawHole(fallenHole);
    DrawCircle(previousBallPosition.x, previousBallPosition.y, ballRadius * scale, BG_COLOR);
    ball.position = Vector2::Lerp(ball.position, fallenHole.position, deltaTime * 10);
    scale *= 0.995;
    DrawCircle(ball.position.x, ball.position.y, ballRadius * scale, PLAYER_COLOR);
    
    Serial.println(abs((ball.position - fallenHole.position).Magnitude()));
    if (abs((ball.position - fallenHole.position).Magnitude()) <= 1) 
    {
      DrawCircle(ball.position.x, ball.position.y, ballRadius * scale, BG_COLOR);
      ball.position = startPosition;
      ball.velocity = {0, 0};
      DrawHole(fallenHole);
      fallenHole = Hole();
      isDying = false;
      scale = 1;
      timer = 0;
    }
    return;
  }

  tilt.x = accelData.accelY;
  tilt.y = -accelData.accelX;
  
	ball.velocity += tilt * acceleration * deltaTime;
	ball.position += ball.velocity * deltaTime;
  
	ball.velocity = ball.velocity * friction;
  if (ball.velocity.Magnitude() > maxSpeed) 
  {
    ball.velocity = ball.velocity.Normalize() * maxSpeed;
  }

  DrawCircle(previousBallPosition.x, previousBallPosition.y, ballRadius, BG_COLOR);
  DrawCircle(ball.position.x, ball.position.y, ballRadius, PLAYER_COLOR);

  DrawShape(shapes[shapeIndex % shapes.size()], LINE_COLOR);
  shapeIndex++;
  
  for (int i = 0; i < holes.size(); i++)
  {
    Vector2 dir = (holes[i].position - ball.position);
    if (dir.SqrMagnitude() < holes[i].radius * holes[i].radius + ballRadius * ballRadius * 4) 
    {
      DrawHole(holes[i]);
      hasHole = true;
      h = holes[i];
    }
    
    if (dir.SqrMagnitude() < holes[i].radius * holes[i].radius + ballRadius * ballRadius * 0.5) 
    {
      isDying = true;
      fallenHole = holes[i];
      ball.velocity = {0, 0};
      ball.velocity += dir * deltaTime * 100;
      DrawCircle(ball.position.x, ball.position.y, ballRadius * scale, BG_COLOR);
      return;
    }
  }

  if (hasHole) 
  {
    Vector2 dir = (h.position - ball.position);
    if (dir.SqrMagnitude() <= h.radius * h.radius + (ballRadius + 1) * (ballRadius + 1) * 4) 
    {
      DrawHole(h);
    }
    else
    {
      hasHole = false;
      DrawHole(h);
    }
  }
  
	for (int i = 0; i < shapes.size(); i++)
	{
		Vector2 closestPoint = shapes[i].GetClosestPointOnShape(ball.position);
		float sqrtDistance = (closestPoint - ball.position).SqrMagnitude();

		if (sqrtDistance < ballRadius * ballRadius)
		{
			Vector2 edgeNormal = (ball.position - closestPoint).Normalize();

			if (Vector2::Dot(ball.velocity, edgeNormal) < 0)
			{
        DrawCircle(ball.position.x, ball.position.y, ballRadius, BG_COLOR);
				ball.position = closestPoint + edgeNormal * ballRadius;
        DrawCircle(ball.position.x, ball.position.y, ballRadius, PLAYER_COLOR);
        
        vibrationTimer = 0.125;
        
        float dot = constrain(-Vector2::Dot(edgeNormal, ball.velocity.Normalize()) + 0.3, 0, 1);

        float vibIntensity = constrain(constrain(ball.velocity.Magnitude() / (maxSpeed * 0.5), 0.0, 1.0) * 255 * dot * 2, 0, 255);
        if (vibIntensity < 50) 
        {
          vibIntensity = 0;
        }
        analogWrite(VIB_PIN, vibIntensity);

				Vector2 refelectedVelocity = ball.velocity - edgeNormal * (Vector2::Dot(edgeNormal, ball.velocity) + collisionDampening * Vector2::Dot(edgeNormal, ball.velocity));
				ball.velocity = refelectedVelocity;

        DrawShape(shapes[i], LINE_COLOR);

        e = shapes[i].GetClosestEdgeOfShape(ball.position);
        hasEdge = true;
			}
		}
	}

  if (hasEdge) 
  {
    Vector2 closestPoint = e.GetClosestPointOnEdge(ball.position);
		float sqrtDistance = (closestPoint - ball.position).SqrMagnitude();

    if (sqrtDistance <= (ballRadius + 1) * (ballRadius + 1)) 
    {
      DrawEdge(e, LINE_COLOR);
    }
    else
    {
      hasEdge = false;
      DrawEdge(e, LINE_COLOR);
    }
  }

  if ((goal - ball.position).SqrMagnitude() < ballRadius * ballRadius + 49) 
  {
    hasWon = true;
  }

  tft.fillCircle(goal.x, goal.y, goalRad, HOLE_COLOR2);
  DrawCircle(goal.x, goal.y, goalRad, HOLE_COLOR3);
  DrawCircle(goal.x, goal.y, goalRad - 2, HOLE_COLOR3);
  DrawCircle(goal.x, goal.y, curGoalRadAnim, BG_COLOR);
  curGoalRadAnim += deltaTime * goalAnimSpeed;
  DrawCircle(goal.x, goal.y, curGoalRadAnim, LINE_COLOR);
  
  if (curGoalRadAnim > 10) 
  {
    curGoalRadAnim = 10;
    goalAnimSpeed *= -1;
  }

  if (curGoalRadAnim < goalRad) 
  {
    curGoalRadAnim = goalRad;
    goalAnimSpeed *= -1;
  }
}

void DrawShapes(const std::vector<Shape>& shapes, uint32_t color)
{
	for (int i = 0; i < shapes.size(); i++)
	{
		DrawShape(shapes[i], color);
	}
}

void DrawShape(const Shape& shape, uint32_t color) 
{
	for (int i = 0; i < shape.vertices.size(); i++)
	{
		if (!shape.closeShape && i == shape.vertices.size() - 1) { break; }

		Vector2 p1 = shape.vertices[i];
		Vector2 p2 = shape.vertices[(i + 1) % shape.vertices.size()];
		DrawLine(p1.x, p1.y, p2.x, p2.y, color);
	}
}

void DrawEdges(const std::vector<Edge>& edges, uint32_t color) 
{
	for (int i = 0; i < edges.size(); i++)
	{
		DrawEdge(edges[i], color);
	}
}

inline void DrawEdge(const Edge& edge, uint32_t color)
{
	DrawLine(edge.p1.x, edge.p1.y, edge.p2.x, edge.p2.y, color);
}

inline void DrawLine(float x1, float y1, float x2, float y2, uint32_t color) 
{
  tft.drawLine(x1, y1, x2, y2, color);
}

inline void DrawCircle(float x, float y, float r, uint32_t color)
{
  tft.drawCircle(x, y, r, color);
}

inline void DrawHoles(const std::vector<Hole>& holes)
{
  for (int i = 0; i < holes.size(); i++)
  {
    DrawHole(holes[i]);
  }
}

inline void DrawHole(const Hole hole)
{
  tft.fillCircle(hole.position.x, hole.position.y, hole.radius, HOLE_COLOR);
  DrawCircle(hole.position.x, hole.position.y, hole.radius, LINE_COLOR);
  DrawCircle(hole.position.x, hole.position.y, hole.radius - 2, HOLE_COLOR3);
  DrawCircle(hole.position.x, hole.position.y, hole.radius - 4, HOLE_COLOR2);
}
