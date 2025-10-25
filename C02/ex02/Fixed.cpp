#include "Fixed.hpp"

const int Fixed::numFracBits = 8;

Fixed::Fixed() : num(0)
{
}

Fixed::Fixed(const int num)
{
    setRawBits(round(num * (1 << numFracBits)));
}

Fixed::Fixed(const float num)
{
    setRawBits(round(num * (1 << numFracBits)));
}

Fixed::Fixed(const Fixed& x)
{
    *this = x;
}

Fixed& Fixed::operator= (const Fixed& f)
{
    this->num = f.getRawBits();
    return (*this);
}

std::ostream& operator<< (std::ostream& OUT, const Fixed & f)
{
    OUT << f.toFloat();
    return (OUT);
}

Fixed::~Fixed()
{ 
}

int Fixed::getRawBits(void) const
{
    return (num);
}

void Fixed::setRawBits(int const raw)
{
    this->num = raw;
}

int Fixed::toInt( void ) const
{
    return (getRawBits() >> numFracBits);
}

float Fixed::toFloat( void ) const
{
    return (getRawBits() / (float)(1 << numFracBits));
}

// ! Comparison operator overloading
bool    Fixed::operator>(const Fixed& f) const
{
    return (this->getRawBits() > f.getRawBits());
}

bool    Fixed::operator<(const Fixed& f) const
{
    return (this->getRawBits() < f.getRawBits());
}

bool    Fixed::operator>=(const Fixed& f) const
{
    return (this->getRawBits() >= f.getRawBits());
}

bool    Fixed::operator<=(const Fixed& f) const
{
    return (this->getRawBits() <= f.getRawBits());
}

bool    Fixed::operator==(const Fixed& f) const
{
    return (this->getRawBits() == f.getRawBits());
}

bool    Fixed::operator!=(const Fixed& f) const
{
    return (this->getRawBits() != f.getRawBits());
}

// ! arithmetic operators
Fixed Fixed::operator+(const Fixed& f) const
{
    Fixed result((this->getRawBits() + f.getRawBits()) / (float)(1 << this->numFracBits));
    return (result);
}

Fixed Fixed::operator-(const Fixed& f) const
{
    Fixed result((this->getRawBits() - f.getRawBits()) / (float)(1 << this->numFracBits));
    return (result);
}

Fixed Fixed::operator*(const Fixed& f) const
{
    Fixed result((this->getRawBits() * f.getRawBits()) / (float)(1 << (this->numFracBits << 1)));
    return (result);
}

Fixed Fixed::operator/(const Fixed& f) const
{
    if (!f.getRawBits())
    {
        std::cerr << "error: division by zero" << std::endl;
        exit(1);
    }
    Fixed result((this->getRawBits() / (float)f.getRawBits()));
    return (result);
}

// ! Increament & Decreament
// ? Pre-Fix
Fixed&   Fixed::operator++()
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed&   Fixed::operator--()
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

// ? Post-Fix
Fixed   Fixed::operator++(int)
{
    Fixed   result = *this;

    this->setRawBits(this->getRawBits()+1);
    return (result);
}

Fixed   Fixed::operator--(int)
{
    Fixed   result = *this;

    this->setRawBits(this->getRawBits()+1);
    return (result);
}

// ! max & min

Fixed&          Fixed::min(Fixed& f1, Fixed& f2)
{
    return ((f1 < f2) ? f1 : f2);
}

const Fixed&    Fixed::min(const Fixed& f1, const Fixed& f2)
{
    return ((f1 < f2) ? f1 : f2);
}

Fixed&          Fixed::max(Fixed& f1, Fixed& f2)
{
    return ((f1 > f2) ? f1 : f2);
}

const Fixed&    Fixed::max(const Fixed& f1, const Fixed& f2)
{
    return ((f1 > f2) ? f1 : f2);
}
