#ifndef LINE_H
#define LINE_H
#include "point.h"

class Line {
private:
    Point p1;
    Point p2;
public:
    bool operator!=(Line another);
    bool operator==(Line another);

    Line(Point _x, Point _y): p1(_x), p2(_y) {}
    Line turn90() const;
    Point reflex(const Point&) const;
    Line moveTo(const Point&) const;
};

#endif