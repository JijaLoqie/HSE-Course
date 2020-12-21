#include "rectangle.h"
#include <cmath>
#include <vector>

Rectangle::Rectangle(const Point& A, const Point& C, double k)
    : Polygon(std::vector<Point>())
{
  double len = dotProduct(A - C, A - C);
  double b = std::sqrt(len / (k * k + 1));
  double a = k * b;
  Point center = (A + C) * (1 / 2);
  Point B = center + (A - center).rotate(2 * atan2(a / len, b / len));
  Point D = center + (B - center).reflex();
  Vertices.push_back(A);
  Vertices.push_back(B);
  Vertices.push_back(C);
  Vertices.push_back(D);
  if (!isClockwise(Vertices))
  {
    Point tmp = Vertices[1];
    Vertices[1] = Vertices[3];
    Vertices[3] = tmp;
  }
}

std::pair<Line, Line> Rectangle::diagonals() const
{
  return std::make_pair(Line(Vertices[0], Vertices[2]), Line(Vertices[1], Vertices[3]));
}
