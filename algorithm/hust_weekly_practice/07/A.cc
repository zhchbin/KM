#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

struct Point {
  double x;
  double y;
};

double getSlopeOfPerpendicular(Point &p1, Point &p2) {
  if (p1.x == p2.x)
    return 0;

  return (p2.x - p1.x) / (p1.y - p2.y);
}

Point getMid(Point &p1, Point &p2) {
  Point p;
  p.x = (p1.x + p2.x) / 2;
  p.y = (p1.y + p2.y) / 2;
  return p;
}

double getDis(Point &p1, Point &p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void solve(Point &p1, Point &p2, Point &p3) {
  double k1 = getSlopeOfPerpendicular(p1, p2);
  double k2 = getSlopeOfPerpendicular(p2, p3);
  Point mid1 = getMid(p1, p2);
  Point mid2 = getMid(p2, p3);
  double b1 = mid1.y - k1 * mid1.x;
  double b2 = mid2.y - k2 * mid2.x;

  double x = (b2 - b1) / (k1 - k2);
  double y = k1 * x + b1;
  Point c;
  c.x = x; c.y = y;
  double r = getDis(p1, c);

  printf("(x");
  x >= 0 ? printf(" - ") : printf(" + ");
  printf("%0.3f)^2 + (y", fabs(x));
  y >= 0 ? printf(" - ") : printf(" + ");
  printf("%0.3f)^2 = %0.3f^2\n", fabs(y), r);
  printf("x^2 + y^2");
  x > 0 ? printf(" - ") : printf(" + ");
  printf("%0.3fx", fabs(2 * x));
  y > 0 ? printf(" - ") : printf(" + ");
  printf("%0.3fy", fabs(2 * y));
  double t = pow(x, 2) + pow(y, 2) - pow(r, 2);
  t > 0 ? printf(" + ") : printf(" - ");
  printf("%0.3f = 0\n\n", fabs(t));
}

int main(int argc, char *argv[]) {
  Point p1, p2, p3;
  bool flag = false;
  while (scanf("%lf%lf%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y) != EOF) {
    solve(p1, p2, p3);
  }
  return 0;
}
