#ifndef Circle_H
#define Circle_H
#include <iostream>
#include "point.h"
#include "line.h"

class Triangle : public polygon
{
private:
    
public:
    Triangle(Point p1, Point p2, Point p3);
    Circle circumscribedCircle();
    Circle inscribedCircle();
};


#endif