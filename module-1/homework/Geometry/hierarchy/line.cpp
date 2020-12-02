#include "line.h"
#include "point.h"


bool Line::operator==(Line another) {
    return (p1 == another.p1 && p2 == another.p2 || p1 == another.p2 && p2 == another.p1); 
}
bool Line::operator!=(Line another) {
    return !(*this == another); 
}
Line::Line(Point::Point _x, Point::Point _y): p1(_x), p2(_y) {}
