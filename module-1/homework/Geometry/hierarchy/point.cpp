#include "point.h"

#include <cmath>

Point reverse(Point p)
{
  return Point(p.y, -p.x);
}
double length(Point a)
{
  return sqrt(a.x * a.x + a.y * a.y);
}

bool operator== (Point a, Point b)
{
  return (a.x == b.x && a.y == b.y);
}
bool operator!= (Point a, Point b)
{
  return (a.x != b.x || a.y != b.y);
}
Point operator+ (Point a, Point b)
{
  return Point(a.x + b.x, a.y + b.y);
}
Point operator- (Point a, Point b)
{
  return Point(a.x - b.x, a.y - b.y);
}

Point operator* (double c, const Point &v) { return Point(c * v.x, c * v.y); }

Point operator* (const Point &v, double c) { return Point(c * v.x, c * v.y); }

Point::Point(double _x, double _y) : x(_x), y(_y) {}
Point::Point(const Point &v) : x(v.x), y(v.y) {}
double crossProduct(const Point &a, const Point &b)
{
  return a.x * b.y - a.y * b.x;
}

double dotProduct(const Point &a, const Point &b)
{
  return a.x * b.x + a.y * b.y;
}

Point Point::rotate(double angle) const
{
  return Point(x * cos(angle) - y * sin(angle),
               x * sin(angle) + y * cos(angle));
}
Point Point::reflex() const { return Point(-x, -y); }
Point Point::turn90() const { return Point(y, -x); }
bool isClockwise(const std::vector<Point> &Vertices)
{
  for (size_t i = 0; i < Vertices.size(); ++i)
  {
    Point firstRay = Vertices[i] - Vertices[(i + 1) % Vertices.size()];
    Point secondRay = Vertices[(i + 2) % Vertices.size()] - Vertices[(i + 1) % Vertices.size()];
    if (crossProduct(firstRay, secondRay) < 0)
    {
      return false;
    }
  }
  return true;
}

bool inSegment(const Point &s1, const Point &s2, const Point &p)
{
  bool inSameLine = doubleEq(crossProduct(p - s1, s2 - s1), 0);
  bool inRay1 = dotProduct(p - s1, s2 - s1) >= 0;
  bool inRay2 = dotProduct(p - s2, s1 - s2) >= 0;
  return inSameLine && inRay1 && inRay2;
}
bool doubleEq(double a, double b) {
  const double eps = 1e-6;
  return abs(a - b) < eps;
}

