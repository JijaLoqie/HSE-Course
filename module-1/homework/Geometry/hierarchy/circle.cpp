#include "circle.h"


Circle::Circle(const Point& _p, double _r): Ellipse(_p, _p, _r) {}
double Circle::radius() const {
    return d;
}
