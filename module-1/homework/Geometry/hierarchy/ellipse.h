#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <iostream>
#include "point.h"
#include "line.h"

class Ellipse {
private:
    Point focus1;
    Point focus2;
    double d;

public:
    std::pair<Point,Point> focuses();
    std::pair<Line, Line> directrices();
    double eccentricity();
    Point center();
    Ellipse(Point, Point, double) {}

};


#endif