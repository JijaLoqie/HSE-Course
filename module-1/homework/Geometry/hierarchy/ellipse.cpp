#include "ellipse.h"

Ellipse::Ellipse(Point a, Point b, double _d):focus1(a), focus2(b), d(_d) {}

std::pair<Point, Point> Ellipse::focuses() {
    return std::make_pair(focus1, focus2);
}
Point Ellipse::center() {
    return Point((focus1.x + focus2.x)/2, (focus1.y + focus2.y)/2);
}

std::pair<Line, Line> Ellipse::directrices() {
    Line l1(focus1, focus2);
    Point tmp(reverse(focus1 - focus2) + center());
    Line l2(tmp, center());

    return std::make_pair(l1, l2);

}
double Ellipse::eccentricity() {
    double c = length(focus1 - focus2) / 2;
    return c / (d - c);
}