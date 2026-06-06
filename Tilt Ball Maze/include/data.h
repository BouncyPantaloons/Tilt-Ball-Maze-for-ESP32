#include "geo.h"

Vector2 startPosition = { 162, 16 };
std::vector<Shape> lvlShapes = std::vector<Shape>
{
    Shape(std::vector<Vector2>{
        {239.5, 0.5},{0.5, 0.5},{0.5, 319.5},{239.5, 319.5},{239.5, 0.5},
    }, true),
    Shape(std::vector<Vector2>{
        {239.5, 247.5},{218.0, 269.0},{218.0, 319.5},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 115.0},{232.5, 179.5},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 213.0},{232.5, 245.5},{211.0, 267.0},{211.0, 319.5},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 0.5},{232.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {134.5, 75.0},{80.0, 88.516},{72.0, 88.516},{72.0, 44.0},{103.5, 44.0},{103.5, 29.0},{56.0, 29.0},{56.0, 56.0},{36.0, 56.0},{36.0, 70.0},{56.0, 70.0},{56.0, 104.707},{68.0, 104.707},{68.0, 115.5},{80.0, 115.5},{80.0, 104.707},{134.5, 90.0},
    }, false),
    Shape(std::vector<Vector2>{
        {147.5, 0.5},{147.5, 31.5},{197.0, 31.5},{197.0, 46.0},{132.5, 46.0},{132.5, 0.5},
    }, false),
    Shape(std::vector<Vector2>{
        {134.5, 75.0},{232.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {134.5, 90.0},{137.5, 90.0},{137.5, 107.5},{149.5, 107.5},{149.5, 90.0},{183.5, 90.0},{232.5, 115.0},
    }, false),
    Shape(std::vector<Vector2>{
        {0.5, 56.5},{15.0, 56.5},{15.0, 70.5},{0.5, 70.5},
    }, false),
    Shape(std::vector<Vector2>{
        {0.5, 189.5},{1.0, 182.5},{2.0, 178.5},{4.0, 174.0},{7.0, 169.5},{10.5, 166.0},{14.5, 163.0},{18.0, 161.0},{24.5, 159.0},{31.5, 158.5},{93.5, 158.5},{100.5, 165.5},{106.5, 166.5},{111.5, 172.5},{111.5, 186.0},{118.0, 186.0},{120.5, 188.5},{120.5, 214.0},
    }, false),
    Shape(std::vector<Vector2>{
        {132.5, 231.5},{132.5, 163.5},{137.5, 158.5},{207.5, 158.5},{207.5, 142.0},{199.5, 137.0},{191.0, 132.0},{167.5, 132.0},{167.5, 145.0},{119.5, 145.0},{119.5, 132.0},{107.5, 132.0},{107.5, 145.0},{37.5, 145.0},{0.5, 108.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 179.5},{216.5, 196.5},{215.5, 199.0},{214.0, 201.0},{211.0, 203.0},{207.5, 203.5},{205.0, 203.0},{202.0, 201.0},{200.5, 199.0},{199.5, 196.5},{183.0, 179.5},{149.5, 179.5},{149.5, 195.5},{177.5, 195.5},{195.0, 213.0},{232.5, 213.0},
    }, false),
    Shape(std::vector<Vector2>{
        {120.5, 214.0},{120.5, 224.0},{111.5, 233.5},{120.5, 243.0},{120.5, 264.5},{21.5, 264.5},{21.5, 190.0},{21.5, 188.5},{22.0, 186.5},{22.5, 185.0},{23.5, 183.5},{25.5, 181.5},{27.0, 180.5},{28.5, 180.0},{31.0, 179.5},{67.0, 179.5},{67.0, 239.0},{67.0, 250.0},{88.0, 250.0},{88.0, 247.0},{80.0, 239.0},{80.0, 215.0},{89.5, 205.5},{80.0, 196.0},{80.0, 172.0},{30.5, 172.0},{26.0, 172.5},{24.0, 173.0},{21.5, 174.5},{19.0, 176.5},{16.5, 179.5},{15.0, 182.0},{14.0, 185.5},{14.0, 190.0},{14.0, 277.0},{14.0, 287.5},
    }, false),
    Shape(std::vector<Vector2>{
        {49.5, 274.5},{120.5, 274.5},{120.5, 290.5},{127.5, 283.713},{127.5, 242.0},{179.5, 242.0},{179.5, 284.5},{184.0, 290.0},{188.5, 284.5},{188.5, 242.0},{200.5, 242.0},{211.0, 231.5},{132.5, 231.5},
    }, false),
    Shape(std::vector<Vector2>{
        {158.5, 319.5},{158.5, 275.0},{153.75, 269.5},{149.0, 275.0},{149.0, 319.5},
    }, false),
    Shape(std::vector<Vector2>{
        {93.5, 319.5},{87.5, 313.5},{87.5, 298.5},{77.5, 291.5},{77.5, 319.5},
    }, false),
    Shape(std::vector<Vector2>{
        {49.5, 274.5},{43.5, 280.5},{43.5, 295.5},{33.5, 302.5},{33.5, 287.5},{14.0, 287.5},
    }, false),
    Shape(std::vector<Vector2>{
        {0.5, 58.0},{2.0, 56.5},
    }, false),
    Shape(std::vector<Vector2>{
        {0.5, 66.0},{10.0, 56.5},
    }, false),
    Shape(std::vector<Vector2>{
        {4.0, 70.5},{15.0, 59.5},
    }, false),
    Shape(std::vector<Vector2>{
        {11.5, 71.0},{15.0, 67.5},
    }, false),
    Shape(std::vector<Vector2>{
        {56.5, 34.0},{61.5, 29.0},
    }, false),
    Shape(std::vector<Vector2>{
        {36.0, 62.5},{42.5, 56.0},
    }, false),
    Shape(std::vector<Vector2>{
        {56.0, 42.5},{69.5, 29.0},
    }, false),
    Shape(std::vector<Vector2>{
        {36.5, 70.0},{50.5, 56.0},
    }, false),
    Shape(std::vector<Vector2>{
        {56.0, 50.5},{77.5, 29.0},
    }, false),
    Shape(std::vector<Vector2>{
        {0.5, 114.0},{3.5, 111.0},
    }, false),
    Shape(std::vector<Vector2>{
        {44.5, 70.0},{85.5, 29.0},
    }, false),
    Shape(std::vector<Vector2>{
        {0.5, 122.0},{7.5, 115.0},
    }, false),
    Shape(std::vector<Vector2>{
        {52.5, 70.0},{72.0, 50.5},
    }, false),
    Shape(std::vector<Vector2>{
        {78.5, 44.0},{93.5, 29.0},
    }, false),
    Shape(std::vector<Vector2>{
        {0.5, 130.0},{11.5, 119.0},
    }, false),
    Shape(std::vector<Vector2>{
        {56.0, 74.5},{72.0, 58.5},
    }, false),
    Shape(std::vector<Vector2>{
        {86.5, 44.0},{101.5, 29.0},
    }, false),
    Shape(std::vector<Vector2>{
        {0.5, 138.0},{15.5, 123.0},
    }, false),
    Shape(std::vector<Vector2>{
        {56.0, 82.5},{72.0, 66.5},
    }, false),
    Shape(std::vector<Vector2>{
        {94.5, 44.0},{103.5, 35.0},
    }, false),
    Shape(std::vector<Vector2>{
        {132.5, 6.0},{138.0, 0.5},
    }, false),
    Shape(std::vector<Vector2>{
        {0.5, 146.0},{19.5, 127.0},
    }, false),
    Shape(std::vector<Vector2>{
        {56.0, 90.5},{72.0, 74.5},
    }, false),
    Shape(std::vector<Vector2>{
        {102.5, 44.0},{103.5, 43.0},
    }, false),
    Shape(std::vector<Vector2>{
        {132.5, 14.0},{146.0, 0.5},
    }, false),
    Shape(std::vector<Vector2>{
        {0.5, 154.0},{23.5, 131.0},
    }, false),
    Shape(std::vector<Vector2>{
        {56.0, 98.5},{72.0, 82.5},
    }, false),
    Shape(std::vector<Vector2>{
        {132.5, 22.0},{147.5, 7.0},
    }, false),
    Shape(std::vector<Vector2>{
        {0.5, 162.0},{27.5, 135.0},
    }, false),
    Shape(std::vector<Vector2>{
        {57.5, 105.0},{74.0, 88.5},
    }, false),
    Shape(std::vector<Vector2>{
        {132.5, 30.0},{147.5, 15.0},
    }, false),
    Shape(std::vector<Vector2>{
        {0.5, 170.0},{31.5, 139.0},
    }, false),
    Shape(std::vector<Vector2>{
        {65.5, 105.0},{82.5, 88.0},
    }, false),
    Shape(std::vector<Vector2>{
        {132.5, 38.0},{147.5, 23.0},
    }, false),
    Shape(std::vector<Vector2>{
        {0.5, 178.0},{3.5, 175.0},
    }, false),
    Shape(std::vector<Vector2>{
        {193.5, 242.0},{204.0, 231.5},
    }, false),
    Shape(std::vector<Vector2>{
        {17.0, 161.5},{35.5, 143.0},
    }, false),
    Shape(std::vector<Vector2>{
        {68.0, 110.5},{93.5, 85.0},
    }, false),
    Shape(std::vector<Vector2>{
        {132.5, 46.0},{147.5, 31.0},
    }, false),
    Shape(std::vector<Vector2>{
        {27.5, 159.0},{41.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {71.0, 115.5},{80.0, 106.5},
    }, false),
    Shape(std::vector<Vector2>{
        {82.5, 104.0},{104.0, 82.5},
    }, false),
    Shape(std::vector<Vector2>{
        {140.5, 46.0},{155.0, 31.5},
    }, false),
    Shape(std::vector<Vector2>{
        {36.0, 158.5},{49.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {79.0, 115.5},{80.0, 114.5},
    }, false),
    Shape(std::vector<Vector2>{
        {93.5, 101.0},{114.5, 80.0},
    }, false),
    Shape(std::vector<Vector2>{
        {148.5, 46.0},{163.0, 31.5},
    }, false),
    Shape(std::vector<Vector2>{
        {14.0, 188.5},{30.5, 172.0},
    }, false),
    Shape(std::vector<Vector2>{
        {44.0, 158.5},{57.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {104.5, 98.0},{125.5, 77.0},
    }, false),
    Shape(std::vector<Vector2>{
        {156.5, 46.0},{171.0, 31.5},
    }, false),
    Shape(std::vector<Vector2>{
        {14.0, 196.5},{21.5, 189.0},
    }, false),
    Shape(std::vector<Vector2>{
        {31.0, 179.5},{38.5, 172.0},
    }, false),
    Shape(std::vector<Vector2>{
        {52.0, 158.5},{65.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {115.5, 95.0},{135.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {164.5, 46.0},{179.0, 31.5},
    }, false),
    Shape(std::vector<Vector2>{
        {14.0, 204.5},{21.5, 197.0},
    }, false),
    Shape(std::vector<Vector2>{
        {39.0, 179.5},{46.5, 172.0},
    }, false),
    Shape(std::vector<Vector2>{
        {60.0, 158.5},{73.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {126.5, 92.0},{143.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {172.5, 46.0},{187.0, 31.5},
    }, false),
    Shape(std::vector<Vector2>{
        {14.0, 212.5},{21.5, 205.0},
    }, false),
    Shape(std::vector<Vector2>{
        {47.0, 179.5},{54.5, 172.0},
    }, false),
    Shape(std::vector<Vector2>{
        {68.0, 158.5},{81.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {136.5, 90.0},{151.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {180.5, 46.0},{195.0, 31.5},
    }, false),
    Shape(std::vector<Vector2>{
        {14.0, 220.5},{21.5, 213.0},
    }, false),
    Shape(std::vector<Vector2>{
        {55.0, 179.5},{62.5, 172.0},
    }, false),
    Shape(std::vector<Vector2>{
        {76.0, 158.5},{89.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {137.5, 97.0},{159.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {188.5, 46.0},{197.0, 37.5},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 2.0},{234.0, 0.5},
    }, false),
    Shape(std::vector<Vector2>{
        {14.0, 228.5},{21.5, 221.0},
    }, false),
    Shape(std::vector<Vector2>{
        {63.0, 179.5},{70.5, 172.0},
    }, false),
    Shape(std::vector<Vector2>{
        {84.0, 158.5},{97.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {107.5, 135.0},{110.5, 132.0},
    }, false),
    Shape(std::vector<Vector2>{
        {137.5, 105.0},{149.5, 93.0},
    }, false),
    Shape(std::vector<Vector2>{
        {152.5, 90.0},{167.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 10.0},{239.5, 3.0},
    }, false),
    Shape(std::vector<Vector2>{
        {14.0, 236.5},{21.5, 229.0},
    }, false),
    Shape(std::vector<Vector2>{
        {67.0, 183.5},{78.5, 172.0},
    }, false),
    Shape(std::vector<Vector2>{
        {92.0, 158.5},{105.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {107.5, 143.0},{118.5, 132.0},
    }, false),
    Shape(std::vector<Vector2>{
        {143.0, 107.5},{149.5, 101.0},
    }, false),
    Shape(std::vector<Vector2>{
        {160.5, 90.0},{175.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 18.0},{239.5, 11.0},
    }, false),
    Shape(std::vector<Vector2>{
        {14.0, 244.5},{21.5, 237.0},
    }, false),
    Shape(std::vector<Vector2>{
        {67.0, 191.5},{80.0, 178.5},
    }, false),
    Shape(std::vector<Vector2>{
        {96.7546, 161.745},{119.5, 139.0},
    }, false),
    Shape(std::vector<Vector2>{
        {168.5, 90.0},{183.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 26.0},{239.5, 19.0},
    }, false),
    Shape(std::vector<Vector2>{
        {14.0, 252.5},{21.5, 245.0},
    }, false),
    Shape(std::vector<Vector2>{
        {67.0, 199.5},{80.0, 186.5},
    }, false),
    Shape(std::vector<Vector2>{
        {101.0, 165.5},{121.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {176.5, 90.0},{191.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 34.0},{239.5, 27.0},
    }, false),
    Shape(std::vector<Vector2>{
        {14.0, 260.5},{21.5, 253.0},
    }, false),
    Shape(std::vector<Vector2>{
        {67.0, 207.5},{80.0, 194.5},
    }, false),
    Shape(std::vector<Vector2>{
        {107.0, 167.5},{129.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {184.185, 90.3153},{199.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 42.0},{239.5, 35.0},
    }, false),
    Shape(std::vector<Vector2>{
        {14.0, 268.5},{21.5, 261.0},
    }, false),
    Shape(std::vector<Vector2>{
        {67.0, 215.5},{83.2382, 199.262},
    }, false),
    Shape(std::vector<Vector2>{
        {110.841, 171.659},{137.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {189.411, 93.0887},{207.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 50.0},{239.5, 43.0},
    }, false),
    Shape(std::vector<Vector2>{
        {14.0, 276.5},{26.0, 264.5},
    }, false),
    Shape(std::vector<Vector2>{
        {67.0, 223.5},{87.2935, 203.207},
    }, false),
    Shape(std::vector<Vector2>{
        {111.5, 179.0},{145.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {194.695, 95.8051},{215.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 58.0},{239.5, 51.0},
    }, false),
    Shape(std::vector<Vector2>{
        {14.0, 284.5},{34.0, 264.5},
    }, false),
    Shape(std::vector<Vector2>{
        {67.0, 231.5},{80.0, 218.5},
    }, false),
    Shape(std::vector<Vector2>{
        {112.5, 186.0},{132.5, 166.0},
    }, false),
    Shape(std::vector<Vector2>{
        {140.0, 158.5},{153.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {200.0, 98.5},{223.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 66.0},{239.5, 59.0},
    }, false),
    Shape(std::vector<Vector2>{
        {19.0, 287.5},{42.0, 264.5},
    }, false),
    Shape(std::vector<Vector2>{
        {67.0, 239.5},{80.0, 226.5},
    }, false),
    Shape(std::vector<Vector2>{
        {119.285, 187.215},{132.5, 174.0},
    }, false),
    Shape(std::vector<Vector2>{
        {148.0, 158.5},{161.5, 145.0},
    }, false),
    Shape(std::vector<Vector2>{
        {167.5, 139.0},{174.5, 132.0},
    }, false),
    Shape(std::vector<Vector2>{
        {205.278, 101.222},{231.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 74.0},{239.5, 67.0},
    }, false),
    Shape(std::vector<Vector2>{
        {27.0, 287.5},{50.0, 264.5},
    }, false),
    Shape(std::vector<Vector2>{
        {67.0, 247.5},{80.0, 234.5},
    }, false),
    Shape(std::vector<Vector2>{
        {120.5, 194.0},{132.5, 182.0},
    }, false),
    Shape(std::vector<Vector2>{
        {156.0, 158.5},{182.5, 132.0},
    }, false),
    Shape(std::vector<Vector2>{
        {210.5, 104.0},{239.5, 75.0},
    }, false),
    Shape(std::vector<Vector2>{
        {33.5, 289.0},{58.0, 264.5},
    }, false),
    Shape(std::vector<Vector2>{
        {72.5, 250.0},{81.809, 240.691},
    }, false),
    Shape(std::vector<Vector2>{
        {120.5, 202.0},{132.5, 190.0},
    }, false),
    Shape(std::vector<Vector2>{
        {164.0, 158.5},{190.5, 132.0},
    }, false),
    Shape(std::vector<Vector2>{
        {216.0, 106.5},{239.5, 83.0},
    }, false),
    Shape(std::vector<Vector2>{
        {33.5, 297.0},{43.5, 287.0},
    }, false),
    Shape(std::vector<Vector2>{
        {56.0, 274.5},{66.0, 264.5},
    }, false),
    Shape(std::vector<Vector2>{
        {80.5, 250.0},{85.7215, 244.778},
    }, false),
    Shape(std::vector<Vector2>{
        {120.5, 210.0},{132.5, 198.0},
    }, false),
    Shape(std::vector<Vector2>{
        {149.5, 181.0},{151.0, 179.5},
    }, false),
    Shape(std::vector<Vector2>{
        {172.0, 158.5},{195.756, 134.744},
    }, false),
    Shape(std::vector<Vector2>{
        {221.213, 109.287},{239.5, 91.0},
    }, false),
    Shape(std::vector<Vector2>{
        {64.0, 274.5},{74.0, 264.5},
    }, false),
    Shape(std::vector<Vector2>{
        {120.5, 218.0},{132.5, 206.0},
    }, false),
    Shape(std::vector<Vector2>{
        {149.5, 189.0},{159.0, 179.5},
    }, false),
    Shape(std::vector<Vector2>{
        {180.0, 158.5},{200.818, 137.682},
    }, false),
    Shape(std::vector<Vector2>{
        {226.5, 112.0},{239.5, 99.0},
    }, false),
    Shape(std::vector<Vector2>{
        {72.0, 274.5},{82.0, 264.5},
    }, false),
    Shape(std::vector<Vector2>{
        {112.195, 234.305},{132.5, 214.0},
    }, false),
    Shape(std::vector<Vector2>{
        {151.0, 195.5},{167.0, 179.5},
    }, false),
    Shape(std::vector<Vector2>{
        {188.0, 158.5},{205.682, 140.818},
    }, false),
    Shape(std::vector<Vector2>{
        {231.784, 114.716},{239.5, 107.0},
    }, false),
    Shape(std::vector<Vector2>{
        {80.0, 274.5},{90.0, 264.5},
    }, false),
    Shape(std::vector<Vector2>{
        {116.112, 238.388},{132.5, 222.0},
    }, false),
    Shape(std::vector<Vector2>{
        {159.0, 195.5},{175.0, 179.5},
    }, false),
    Shape(std::vector<Vector2>{
        {196.0, 158.5},{207.5, 147.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 122.0},{239.5, 115.0},
    }, false),
    Shape(std::vector<Vector2>{
        {88.0, 274.5},{98.0, 264.5},
    }, false),
    Shape(std::vector<Vector2>{
        {120.0, 242.5},{132.5, 230.0},
    }, false),
    Shape(std::vector<Vector2>{
        {167.0, 195.5},{183.0, 179.5},
    }, false),
    Shape(std::vector<Vector2>{
        {204.0, 158.5},{207.5, 155.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 130.0},{239.5, 123.0},
    }, false),
    Shape(std::vector<Vector2>{
        {77.5, 293.0},{78.3756, 292.124},
    }, false),
    Shape(std::vector<Vector2>{
        {96.0, 274.5},{106.0, 264.5},
    }, false),
    Shape(std::vector<Vector2>{
        {120.5, 250.0},{127.5, 243.0},
    }, false),
    Shape(std::vector<Vector2>{
        {128.5, 242.0},{139.0, 231.5},
    }, false),
    Shape(std::vector<Vector2>{
        {175.0, 195.5},{187.0, 183.5},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 138.0},{239.5, 131.0},
    }, false),
    Shape(std::vector<Vector2>{
        {77.5, 301.0},{83.0, 295.5},
    }, false),
    Shape(std::vector<Vector2>{
        {104.0, 274.5},{114.0, 264.5},
    }, false),
    Shape(std::vector<Vector2>{
        {120.5, 258.0},{127.5, 251.0},
    }, false),
    Shape(std::vector<Vector2>{
        {136.5, 242.0},{147.0, 231.5},
    }, false),
    Shape(std::vector<Vector2>{
        {180.207, 198.293},{191.0, 187.5},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 146.0},{239.5, 139.0},
    }, false),
    Shape(std::vector<Vector2>{
        {77.5, 309.0},{87.5, 299.0},
    }, false),
    Shape(std::vector<Vector2>{
        {112.0, 274.5},{127.5, 259.0},
    }, false),
    Shape(std::vector<Vector2>{
        {144.5, 242.0},{155.0, 231.5},
    }, false),
    Shape(std::vector<Vector2>{
        {184.237, 202.263},{194.807, 191.693},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 154.0},{239.5, 147.0},
    }, false),
    Shape(std::vector<Vector2>{
        {77.5, 317.0},{87.5, 307.0},
    }, false),
    Shape(std::vector<Vector2>{
        {119.882, 274.618},{127.5, 267.0},
    }, false),
    Shape(std::vector<Vector2>{
        {152.5, 242.0},{163.0, 231.5},
    }, false),
    Shape(std::vector<Vector2>{
        {188.21, 206.29},{198.763, 195.737},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 162.0},{239.5, 155.0},
    }, false),
    Shape(std::vector<Vector2>{
        {83.0, 319.5},{88.2076, 314.292},
    }, false),
    Shape(std::vector<Vector2>{
        {120.5, 282.0},{127.5, 275.0},
    }, false),
    Shape(std::vector<Vector2>{
        {160.5, 242.0},{171.0, 231.5},
    }, false),
    Shape(std::vector<Vector2>{
        {192.242, 210.258},{201.804, 200.696},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 170.0},{239.5, 163.0},
    }, false),
    Shape(std::vector<Vector2>{
        {91.0, 319.5},{92.2485, 318.252},
    }, false),
    Shape(std::vector<Vector2>{
        {168.5, 242.0},{179.0, 231.5},
    }, false),
    Shape(std::vector<Vector2>{
        {197.5, 213.0},{207.0, 203.5},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 178.0},{239.5, 171.0},
    }, false),
    Shape(std::vector<Vector2>{
        {176.5, 242.0},{187.0, 231.5},
    }, false),
    Shape(std::vector<Vector2>{
        {205.5, 213.0},{239.5, 179.0},
    }, false),
    Shape(std::vector<Vector2>{
        {149.0, 277.5},{155.242, 271.258},
    }, false),
    Shape(std::vector<Vector2>{
        {179.5, 247.0},{195.0, 231.5},
    }, false),
    Shape(std::vector<Vector2>{
        {213.5, 213.0},{239.5, 187.0},
    }, false),
    Shape(std::vector<Vector2>{
        {149.0, 285.5},{158.5, 276.0},
    }, false),
    Shape(std::vector<Vector2>{
        {179.5, 255.0},{188.5, 246.0},
    }, false),
    Shape(std::vector<Vector2>{
        {221.5, 213.0},{239.5, 195.0},
    }, false),
    Shape(std::vector<Vector2>{
        {149.0, 293.5},{158.5, 284.0},
    }, false),
    Shape(std::vector<Vector2>{
        {179.5, 263.0},{188.5, 254.0},
    }, false),
    Shape(std::vector<Vector2>{
        {229.5, 213.0},{239.5, 203.0},
    }, false),
    Shape(std::vector<Vector2>{
        {149.0, 301.5},{158.5, 292.0},
    }, false),
    Shape(std::vector<Vector2>{
        {179.5, 271.0},{188.5, 262.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 218.0},{239.5, 211.0},
    }, false),
    Shape(std::vector<Vector2>{
        {149.0, 309.5},{158.5, 300.0},
    }, false),
    Shape(std::vector<Vector2>{
        {179.5, 279.0},{188.5, 270.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 226.0},{239.5, 219.0},
    }, false),
    Shape(std::vector<Vector2>{
        {149.0, 317.5},{158.5, 308.0},
    }, false),
    Shape(std::vector<Vector2>{
        {180.638, 285.862},{188.5, 278.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 234.0},{239.5, 227.0},
    }, false),
    Shape(std::vector<Vector2>{
        {155.0, 319.5},{158.5, 316.0},
    }, false),
    Shape(std::vector<Vector2>{
        {232.5, 242.0},{239.5, 235.0},
    }, false),
    Shape(std::vector<Vector2>{
        {211.0, 271.5},{239.5, 243.0},
    }, false),
    Shape(std::vector<Vector2>{
        {211.0, 279.5},{218.0, 272.5},
    }, false),
    Shape(std::vector<Vector2>{
        {211.0, 287.5},{218.0, 280.5},
    }, false),
    Shape(std::vector<Vector2>{
        {211.0, 295.5},{218.0, 288.5},
    }, false),
    Shape(std::vector<Vector2>{
        {211.0, 303.5},{218.0, 296.5},
    }, false),
    Shape(std::vector<Vector2>{
        {211.0, 311.5},{218.0, 304.5},
    }, false),
    Shape(std::vector<Vector2>{
        {211.0, 319.5},{218.0, 312.5},
    }, false),
};

std::vector<Hole> lvlHoles = std::vector<Hole>
{
    Hole({218, 62},11),
    Hole({86, 73},11),
    Hole({113.5, 107.5},9.5),
    Hole({143.5, 133.5},9.5),
    Hole({182, 105},12),
    Hole({204, 113},9),
    Hole({221.5, 119.5},6.5),
    Hole({208, 195},7),
    Hole({201, 168},7),
    Hole({224.5, 242.5},6.5),
    Hole({146, 218},12),
    Hole({137.5, 307.5},10),
    Hole({108, 287},10),
    Hole({66, 295},10),
    Hole({100.5, 176.5},9.5),
    Hole({100.5, 205.5},9.5),
    Hole({100.5, 233.5},9.5),
    Hole({59, 246},6),
    Hole({30, 256},6),
    Hole({39, 234},6),
    Hole({56, 216},6),
    Hole({33, 209},6),
    Hole({109.5, 253.5},8.5),
    Hole({22, 300},10),
    Hole({201.5, 310.5},7.5),
    Hole({184.5, 310.5},7.5),
    Hole({167.5, 310.5},7.5),
    Hole({170.5, 251},7.5),
    Hole({153.5, 251.5},7.5),
    Hole({136.5, 251.5},7.5),
    Hole({187, 166},5),
    Hole({108, 71},8),
    Hole({121, 12},8),
    Hole({38, 88},15),
    Hole({16.5, 16.5},12.5),
    Hole({42, 42},10),
};
// std::vector<Shape> lvlShapes = std::vector<Shape>
// {
// 		Shape(std::vector<Vector2>
// 		{
// 				{ 1, 1 },
// 				{ 133.333, 1 },
// 				{ 133.333, 46.6667 },
// 				{ 199.333, 46 },
// 				{ 199.333, 33.3333 },
// 				{ 148, 33.3333 },
// 				{ 148, 1 },
// 				{ 240, 1 },
// 				{ 240, 76 },
// 				{ 164.667, 76.6667 },
// 				{ 164.667, 90.6667 },
// 				{ 240.667, 90 },
// 				{ 240, 320 },
// 				{ 1, 320 },
// 				{ 1.33333, 136.667 },
// 				{ 23.3333, 136 },
// 				{ 23.3333, 121.333 },
// 				{ 1.33333, 121.333 },
// 		}, true),
// 		Shape(std::vector<Vector2>
// 		{
// 				{ 104.667, 29.3333 },
// 				{ 104.667, 45.3333 },
// 				{ 72, 45.3333 },
// 				{ 72.6667, 92 },
// 				{ 135.333, 76 },
// 				{ 135.333, 92 },
// 				{ 56, 112.667 },
// 				{ 56, 70.6667 },
// 				{ 36, 70.6667 },
// 				{ 36.6667, 56 },
// 				{ 56.6667, 56 },
// 				{ 56, 29.3333 },
// 		}, true),
// };
// std::vector<Hole> lvlHoles = std::vector<Hole>
// {
// 		Hole({229.333, 64}, 10),
// 		Hole({14.6667, 15.3333}, 10),
// 		Hole({86, 73.3333}, 10),
// 		Hole({43.3333, 41.3333}, 10),
// 		Hole({14, 102}, 10),
// 		Hole({150.667, 84}, 10),
// };