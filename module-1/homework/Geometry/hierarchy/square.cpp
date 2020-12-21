#include "square.h"
#include <cmath>

Square::Square(const Point& a, const Point& b) : Rectangle(a, b, 1.0) {}

Circle Square::circumscribedCircle() const {
  return Circle(center(), length(Vertices[0] - Vertices[2]));
}

Circle Square::inscribedCircle() const {
  return Circle(center(), length(Vertices[0] - Vertices[2]) / std::sqrt(2));
}