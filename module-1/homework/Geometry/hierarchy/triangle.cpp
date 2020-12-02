#include "Circle.h"
#include "polygon.h"
#include "triangle.h"
#include <cmath>


Triangle::Triangle(Point a, Point b, Point c) : Polygon({a, b, c}) {}

Circle Triangle::circumscribedCircle() {
    Point A = vertices[0];
    Point B = vertices[1];
    Point C = vertices[2];
    double a = length(B - C);
    double b = length(A - C);
    double c = length(A - B);
    Point I = (A*a + B*b + C*c) * (1/(a + b + c));
    double r = 2 * area() / (a + b + c);
    return Circle(I, r); 

}
Circle Triangle::inscribedCircle() {
    Point A = vertices[0];
    Point B = vertices[1];
    Point C = vertices[2];
    double a = length(B - C);
    double b = length(A - C);
    double c = length(A - B);
    double k1 = a * (b + c - a);
    double k2 = b * (a + c - b);
    double k3 = c * (b + a - c);
    Point O = (A*k1 + B*k2 + C*k3) * (1/(k1 + k2 + k3));
    double r = std::sqrt(a) * std::sqrt(b) * std::sqrt(c) / (4 * area()) 
    return Circle(O, r); 

}