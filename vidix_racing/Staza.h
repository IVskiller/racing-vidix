#include "Helpers.h"

class Polygon {
public:
  int numOfPoints;
  Matrix<2> *points;

  Polygon(int numOfPoints, Matrix<2> points[]) {
    this->numOfPoints = numOfPoints;
    this->points = points;
  }

  bool inside(Matrix<2> point) {
    float x = point(0);
    float y = point(1);
    bool inside = false;

    Matrix<2> p1 = points[0], p2;
    for (int i = 1; i <= numOfPoints; i++) {
      p2 = points[i % numOfPoints];

      if (y > min(p1(1), p2(1))) {
        if (y <= max(p1(1), p2(1))) {
          if (x <= max(p1(0), p2(0))) {
            float x_intersection = (y - p1(1)) * (p2(0) - p1(0)) / (p2(1) - p1(1)) + p1(0);

            if (p1(0) == p2(0) || x <= x_intersection) {
              inside = !inside;
            }
          }
        }
      }

      p1 = p2;
    }

    return inside;
  }
};

Matrix<2> tockeOuter[] = {
{0,-6},
{-40,-6},
{-87,-27},
{-90,-68},
{-79,-97},
{-70,-115},
{-28, -154},
{-20,-174},
{-26, -202},
{-73,-233},
{-142, -236},
{-167, -212},
{-210,-128},
{-212, -88},
{-230,- 70},
{-251, -29},
{-252, 26},
{-231, 46},
{-214, 79},
{-175, 122},
{-114,151},
{-2, 153},
{42,134},
{75, 133},
{93,153},
{146,152},
{170,130},
{172,81},
{153,40},
{151,0},
{130, -25},
{130, -45},
{107, -113},
{77, -114},
{51,-90},
{47, -65},
{31, -52},
{29,- 24}
};
Matrix<2> tockeInner[] = {
{0,8},
{-40,8},
{-100,-20},
{-100,-70},
{-90,-100},
{-80,-120},
{-60,-140},
{-40,-160},
{-32,-180},
{-40,-200},
{-80,-220},
{-140,-220},
{-160,-200},
{-180,-160},
{-200,-120},
{-200,-80},
{-220,-60},
{-240,-20},
{-240,20},
{-220,40},
{-200,80},
{-160,120},
{-100,140},
{0,140},
{40,120},
{80,120},
{100,140},
{140,140},
{160,120},
{160,80},
{140,40},
{140,0},
{120,-20},
{120,-20},
{120,-40},
{100,-100},
{80,-100},
{60,-80},
{60,-60},
{40,-40},
{40,-20},
{20,0}
};
Polygon stazaInner = Polygon(42, tockeInner);
Polygon stazaOuter = Polygon(38, tockeOuter);