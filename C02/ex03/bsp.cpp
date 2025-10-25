#include "Point.hpp"
#include "Fixed.hpp"
#include <cmath>

static Fixed   areaTriagle(const Point& a, const Point& b, const Point& c)
{
    
    Fixed result(fabsf(((a.getX()-b.getX())*(a.getY()-c.getY())
                    -(a.getY()-b.getY())*(a.getX()-c.getX())).toFloat())/2);
    return (result);
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed abcT(areaTriagle(a, b, c));
    Fixed abpT(areaTriagle(a, b, point));
    Fixed acpT(areaTriagle(a, c, point));
    Fixed bcpT(areaTriagle(b, c, point));

    return (abcT == (abpT + acpT + bcpT));
}
