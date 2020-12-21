#include <cmath>
#include "ellipse.h"

double Ellipse::a() const { return d / 2; }

double Ellipse::b() const
{
    double c = length((focus1 - focus2) * 0.5);
    double a = this->a();
    return sqrt(a * a - c * c);
}



std::pair<Point, Point> Ellipse::focuses() const
{
    return std::make_pair(focus1, focus2);
}
Point Ellipse::center() const
{
    return Point((focus1.x + focus2.x) / 2, (focus1.y + focus2.y) / 2);
}

std::pair<Line, Line> Ellipse::directrices() const
{
    Line l1(focus1, focus2);
    Point tmp(reverse(focus1 - focus2) + center());
    Line l2(tmp, center());

    return std::make_pair(l1, l2);
}
double Ellipse::eccentricity() const
{
    double c = length(focus1 - focus2) / 2;
    return c / (d - c);
}
bool Ellipse::containsPoint(Point point) const
{
    return length(focus1 - point) + length(focus2 - point) <= d;
}

void Ellipse::rotate(Point center, double angle)
{
    focus1 = center + (focus1 - center).rotate(angle);
    focus2 = center + (focus2 - center).rotate(angle);
}

bool Ellipse::isCongruentTo(const Shape &another) const
{
    const Shape *pointer = &another;
    const Ellipse *anotherEllipse = dynamic_cast<const Ellipse *>(pointer);
    if (anotherEllipse)
    {
        return doubleEq(this->a(), anotherEllipse->a()) &&
               doubleEq(this->b(), anotherEllipse->b());
    }
    return false;
}

bool Ellipse::isSimilarTo(const Shape &another) const
{
    const Shape* pointer = &another;
    const Ellipse* anotherEllipse = dynamic_cast<const Ellipse *>(pointer);
    if (anotherEllipse)
    {
        return doubleEq(this->a() / anotherEllipse->a(),
                        this->b() / anotherEllipse->b());
    }
    return false;
}

double Ellipse::perimeter() const
{
    const double pi = 3.1415926;
    double a = this->a();
    double b = this->b();
    return 4 * (pi * a * b + (a - b) * (a - b)) / (a + b);
}

double Ellipse::area() const
{
    double pi = 3.1415926;
    return pi * this->a() * this->b();
}

bool Ellipse::operator==(const Shape &another) const
{
    const Shape *pointer = &another;
    const Ellipse *anotherEllipse = dynamic_cast<const Ellipse *>(pointer);
    if (anotherEllipse)
    {
        bool ffEqual = focus1 == anotherEllipse->focus1;
        bool ssEqual = focus2 == anotherEllipse->focus2;
        bool fsEqual = focus1 == anotherEllipse->focus2;
        bool sfEqual = focus2 == anotherEllipse->focus1;
        bool radiusEqual = doubleEq(d, anotherEllipse->d);
        return (ffEqual && ssEqual || fsEqual && sfEqual) && radiusEqual;
    }
    return false;
}

void Ellipse::reflex(Point center)
{
    focus1 = center + (focus1 - center).reflex();
    focus2 = center + (focus2 - center).reflex();
}

void Ellipse::reflex(Line axis)
{
    focus1 = axis.reflex(focus1);
    focus2 = axis.reflex(focus2);
}

void Ellipse::scale(Point center, double coefficient)
{
    d *= coefficient;
    focus1 = center + coefficient * (focus1 - center);
    focus2 = center + coefficient * (focus2 - center);
}