#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "line.h"
#include "point.h"
#include "shape.h"

class Ellipse : public Shape 
{
protected:
    double d;
    Point focus1;
    Point focus2;
private:
    double a() const;
    double b() const;
public:
    Ellipse(Point a, Point b, double _d) : focus1(a), focus2(b), d(_d) {}
    std::pair<Point, Point> focuses() const;
    std::pair<Line, Line> directrices() const;
    double eccentricity() const;
    Point center() const;


    double perimeter() const override;
    double area() const override;
    bool operator==(const Shape &another) const override;
    bool isCongruentTo(const Shape &another) const override;
    bool isSimilarTo(const Shape &another) const override;
    bool containsPoint(Point point) const override;
    void rotate(Point center, double angle) override;
    void reflex(Point center) override;
    void reflex(Line axis) override;
    void scale(Point center, double coefficient) override;
};

#endif