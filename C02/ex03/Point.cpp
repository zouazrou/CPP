#include "Point.hpp"

Point::Point() : x(0), y(0)
{}

Point::Point(const float x, const float y) : x(x), y(y)
{}

Point::Point(const Point& point) : x(point.x), y(point.y)
{}

Point& Point::operator =(const Point &point)
{
    (void)point;
    return (*this);
}

Point::~Point()
{
}

const Fixed   Point::getX(void) const
{
    return (this->x);
}

const Fixed   Point::getY(void) const
{
    return (this->y);
}
