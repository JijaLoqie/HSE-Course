#include "line.h"
#include "point.h"


bool Line::operator==(Line another) {
    return (p1 == another.p1 && p2 == another.p2 || p1 == another.p2 && p2 == another.p1); 
}
bool Line::operator!=(Line another) {
    return !(*this == another); 
}
Line Line::turn90() const {
  Line result = *this;
  result.p2 = p1 + (p2 - p1).turn90();
  return result;
}

Point Line::reflex(const Point& p) const {
  Point v = p - p2;
  Point l = p1 - p2;
  return p2 + ((2 * dotProduct(v, l) / dotProduct(l, l)) * l - v);
}

Line Line::moveTo(const Point& p) const {
  Line result = *this;
  Point v = p - p1;
  result.p1 = p1 + v;
  result.p2 = p2 + v;
  return result;
}