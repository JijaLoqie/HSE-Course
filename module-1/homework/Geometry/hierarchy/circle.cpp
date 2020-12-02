#include "circle.h"



Circle::Circle(Point _p, double _r): cent(_p), rad(_r) {}
double Circle::radius() {
    return rad;
}