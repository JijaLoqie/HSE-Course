#include "polygon.h"
#include <cmath>
#include <iostream>
std::vector<Point> Polygon::getVertices()
{
  return Vertices;
}
std::size_t Polygon::verticesCount()
{
  return Vertices.size();
}
bool Polygon::isConvex()
{
  bool firstTry = true;
  bool convexity = true;
  bool plus = false;
  for (std::size_t i = 0; i < verticesCount(); i++)
  {
    Point ab(Vertices[i].x - Vertices[i - 1].x,
             Vertices[i].y - Vertices[i - 1].y);

    Point bc(Vertices[i + 1].x - Vertices[i].x,
             Vertices[i + 1].y - Vertices[i].y);

    double product = ab.x * bc.y - ab.y * bc.x;
    if (firstTry)
    {
      firstTry = !firstTry;
      plus = (product > 0);
    }
    else if (plus && product <= 0 || !plus && product > 0)
    {
      convexity = 0;
      break;
    }
  }
  return convexity;
}
Polygon::Polygon(std::vector<Point> _v) : Vertices(_v) {}

bool Polygon::isSimilarTo(const Shape& another) const
{
  const Shape* pointer = &another;
  const Polygon* anotherP = dynamic_cast<const Polygon* >(pointer);
  if (anotherP)
  {
    size_t n = Vertices.size();
    if (n == anotherP->Vertices.size())
    {
      for (size_t i = 0; i < n; i++)
      {
        bool isAnswerYes = true;
        double k = -1.0;
        for (size_t j = 0; j < n; ++j)
        {
          Point d1 = Vertices[j] - Vertices[(j + 1) % n];
          Point d2 = Vertices[(j + 2) % n] - Vertices[(j + 1) % n];
          Point anotherD1 =
              anotherP->Vertices[(i + j) % n] - anotherP->Vertices[(i + j + 1) % n];
          Point anotherD2 = anotherP->Vertices[(i + j + 2) % n] -
                            anotherP->Vertices[(i + j + 1) % n];
          double cp = crossProduct(d1, d2);
          double anotherCp = crossProduct(anotherD1, anotherD2);
          double dp = dotProduct(d1, d2);
          double anotherDp = dotProduct(anotherD1, anotherD2);
          if (k < 0)
          {
            k = length(anotherD1) / length(d1);
          }
          if (anotherCp == k * k * cp && anotherDp == k * k * dp)
          {
            isAnswerYes = false;
            break;
          }
        }
        if (isAnswerYes)
        {
          return true;
        }
      }
    }
  }
  return false;
}

double Polygon::perimeter() const
{
  size_t n = Vertices.size();
  double result = 0;
  for (size_t i = 0; i < n; i++)
  {
    result += length(Vertices[(i + 1) % n] - Vertices[i]);
  }
  return result;
}

double Polygon::area() const
{
  size_t n = Vertices.size();
  double result = 0;
  for (size_t i = 0; i < n; i++)
  {
    result += crossProduct(Point(Vertices[i]), Point(Vertices[(i + 1) % n]));
  }
  return result / 2;
}

void Polygon::reflex(Point center)
{
  for (size_t i = 0; i < Vertices.size(); i++)
  {
    Point centerToPoint = Vertices[i] - center;
    Vertices[i] = center + centerToPoint.reflex();
  }
}

void Polygon::reflex(Line axis)
{
  int n = Vertices.size();
  for (size_t i = 0; i < n; i++)
  {
    Vertices[i] = axis.reflex(Vertices[i]);
  }
  for (int i = 0; i < Vertices.size() / 2; i++)
  {
    Point tmp = Vertices[i];
    Vertices[i] = Vertices[n - i - 1];
    Vertices[n - i - 1] = tmp;
  }
}

void Polygon::scale(Point center, double coefficient)
{
  for (size_t i = 0; i < Vertices.size(); i++)
  {
    Vertices[i] = center + coefficient * (Vertices[i] - center);
  }
}
void Polygon::rotate(Point center, double angle)
{
  angle = angle * pi / 180;
  for (size_t i = 0; i < Vertices.size(); i++)
  {
    Vertices[i] = center + (Vertices[i] - center).rotate(angle);
  }
}

bool Polygon::containsPoint(Point point) const
{
  double ang = 0;
  size_t n = Vertices.size();
  for (size_t i = 0; i < n; i++)
  {
    Point firstRay = Vertices[i] - point;
    Point secondRay = Vertices[(i + 1) % n] - point;
    double cp = crossProduct(firstRay, secondRay);
    double dp = dotProduct(firstRay, secondRay);
    ang += std::atan2(cp, dp);
  }
  for (size_t i = 0; i < n; i++)
  {
    if (inSegment(Vertices[i], Vertices[(i + 1) % n], point))
    {
      return true;
    }
  }
  return doubleEq(ang, 2 * pi);
}

bool Polygon::operator ==(const Shape& another) const
{
  const Shape* pointer = &another;
  const Polygon* anotherP = dynamic_cast<const Polygon* >(pointer);
  if (anotherP)
  {
    size_t n = Vertices.size();
    if (n != anotherP->Vertices.size())
    {
      return false;
    }
    for (size_t i = 0; i < n; i++)
    {
      bool isAnswerYes = true;
      for (size_t j = 0; j < n; ++j)
      {
        if (Vertices[j] != anotherP->Vertices[(i + j) % n])
        {
          isAnswerYes = false;
          break;
        }
      }
      if (isAnswerYes)
      {
        return true;
      }
    }
  }
  return false;
}
bool Polygon::isCongruentTo(const Shape& another) const
{
  const Shape* pointer = &another;
  const Polygon* anotherP = dynamic_cast<const Polygon* >(pointer);
  if (anotherP)
  {
    size_t n = Vertices.size();
    if (n == anotherP->Vertices.size())
    {
      for (size_t i = 0; i < n; i++)
      {
        bool isAnswerYes = true;
        for (size_t j = 0; j < n; ++j)
        {
          Point d = Vertices[(j + 1) % n] - Vertices[j];
          Point anotherD = anotherP->Vertices[(i + j + 1) % n] - anotherP->Vertices[(i + j) % n];
          if (Point(d) != Point(anotherD))
          {
            isAnswerYes = false;
          }
        }
        if (isAnswerYes)
        {
          return true;
        }
      }
    }
  }
  return false;
}
