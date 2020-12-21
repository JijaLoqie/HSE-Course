
#ifndef CIRCLE_H
#define CIRCLE_H
#include "ellipse.h"
#include "line.h"
#include "point.h"

class Circle : public Ellipse {
 public:
  Circle(const Point&, double);
  double radius() const;
};

#endif