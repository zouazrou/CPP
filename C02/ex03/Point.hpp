#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;

public:
    // * Orthodox form
    Point();
    Point(const float x, const float y);
    Point(const Point& f);
    Point& operator =(const Point &point);
    ~Point();

    // * getter
    const Fixed   getX(void) const;
    const Fixed   getY(void) const;


};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif