#ifndef POINT_H
#define POINT_H
#include <vector>



struct Point
{
  double x;
  double y;
  Point();
  Point(double, double);
  Point(const Point &);
  Point rotate(double) const;
  Point reflex() const;
  Point turn90() const;
};
bool doubleEq(double, double);
Point reverse(Point p);
double length(Point a);

bool operator==(Point a, Point b);
bool operator!=(Point a, Point b);
Point operator+(Point a, Point b);
Point operator-(Point a, Point b);

Point operator*(double c, const Point &v);
Point operator*(const Point &v, double c);
double crossProduct(const Point &a, const Point &b);
double dotProduct(const Point &a, const Point &b);
bool inSegment(const Point &, const Point &, const Point &);
bool isClockwise(const std::vector<Point> &);
#endif