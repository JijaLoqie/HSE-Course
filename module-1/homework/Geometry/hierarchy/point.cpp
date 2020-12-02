#include <iostream>
#include <cmath>
#include "point.h"

Point reverse(Point p) {
  return Point(p.y, -p.x);
}
double length(Point a) {
    return sqrt(a.x * a.x + a.y*a.y);
}


bool Point::operator==(Point another) {
    return (x == another.x && y == another.y); 
}
bool Point::operator!=(Point another) {
    return (x != another.x || y != another.y); 

}
Point Point::operator+(Point another) {
    return Point(x + another.x, y + another.y);  
}
Point Point::operator-(Point another) {
    return Point(x - another.x, y - another.y);
}
Point Point::operator*(double another) {
    return Point(x * another, y * another);
}
Point::Point(double _x, double _y): x(_x), y(_y) {}


double crossProduct(const Point& a, const Point& b) {
  return a.x * b.y - a.y * b.x;
}

double dotProduct(const Point& a, const Point& b) {
  return a.x * b.x + a.y * b.y;
}