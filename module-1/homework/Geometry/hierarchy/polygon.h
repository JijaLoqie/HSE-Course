#ifndef POLYGON_H
#define POLYGON_H
#include "point.h"
#include "line.h"
#include <vector>

class Polygon {
    std::vector<Point> Vertices;
    std::size_t verticesCount();
public:
    Polygon(std::vector<Point>);
    std::vector<Point> getVertices();
    bool isConvex();
};

#endif