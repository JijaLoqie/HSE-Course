#ifndef Circle_H
#define Circle_H
#include <iostream>
#include "point.h"
#include "line.h"
#include "ellipse.h"

class Circle : public Ellepse
{
private:
    double rad;
    Point cent;
public:
    Circle(Point, double);
    double radius();
};


#endif