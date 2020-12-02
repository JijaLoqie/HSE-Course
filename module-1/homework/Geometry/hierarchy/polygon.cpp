#include "point.h"
#include "polygon.h"
#include <vector>

std::vector<Point> Polygon::getVertices()
{
    return Vertices;
}
std::size_t Polygon::verticesCount()
{
    return Vertices.size();
}
bool Polygon::isConvex()
{
    bool ok1 = false;
    bool ok2 = true;
    bool plus = false;
    for (std::size_t i = 0; i < verticesCount(); i++)
    {
        Point ab(Vertices[i].x - Vertices[i - 1].x,
                Vertices[i].y - Vertices[i - 1].y);

        Point bc(Vertices[i + 1].x - Vertices[i].x,
                Vertices[i + 1].y - Vertices[i].y);

        double product = ab.x * bc.y - ab.y * bc.x;
        if (!ok1)
        {
            ok1 = !ok1;
            plus = (product > 0);
        }
        else if (plus && product <= 0 || !plus && product > 0)
        {
            ok2 = 0;
            break;
        }
    }
    return ok2;
}
Polygon::Polygon(std::vector<Point> _v): Vertices(_v){}

