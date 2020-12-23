#ifndef Circle_H
#define Circle_H
#include <iostream>
#include "point.h"
#include "polygon.h"
#include "circle.h"

class Triangle : public Polygon
{
private:
    
public:
    Triangle(Point p1, Point p2, Point p3);
    Circle circumscribedCircle() const;
    Circle inscribedCircle() const;
};


#endif