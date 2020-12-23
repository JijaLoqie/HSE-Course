#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "line.h"
#include "point.h"
#include "shape.h"

class Polygon : public Shape {
private:
    const double pi = 3.1415926;
    std::size_t verticesCount();
public:
    Polygon(std::vector<Point>);
    std::vector<Point> getVertices();
    bool isConvex();
    std::vector<Point> Vertices;

    double perimeter() const override;
    double area() const override;
    bool operator== (const Shape& another) const override;
    bool isCongruentTo(const Shape& another) const override;
    bool isSimilarTo(const Shape& another) const override;
    bool containsPoint(Point point) const override;
    void rotate(Point center, double angle) override;
    void reflex(Point center) override;
    void reflex(Line axis) override;
    void scale(Point center, double coefficient) override;
    void print();
    void Normalize(std::vector<Point>&); 
};

#endif