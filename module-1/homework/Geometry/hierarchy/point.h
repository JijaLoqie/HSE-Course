#ifndef POINT_H
#define POINT_H

bool doubleEq(double, double);

Point reverse(Point p);
double length(Point a);

struct Point {
  double x;
  double y;
  Point(double, double);
  bool operator!=(Point another);
  bool operator==(Point another);
  Point operator+(Point another);
  Point operator-(Point another);
  Point operator*(double another);

};


#endif