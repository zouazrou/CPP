#include "Fixed.hpp"

const int Fixed::numFracBits = 8;

Fixed::Fixed() : num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(round(num * (1 << numFracBits)));
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    setRawBits(round(num * (1 << numFracBits)));
}

Fixed::Fixed(const Fixed& x)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = x;
}

Fixed& Fixed::operator= (const Fixed& f)
{
    std::cout << "Copy assignment operator called" << std::endl;
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
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (num);
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
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
    return (this->toFloat() > f.toFloat());
}

bool    Fixed::operator<(const Fixed& f) const
{
    return (this->toFloat() < f.toFloat());
}

bool    Fixed::operator>=(const Fixed& f) const
{
    return (this->toFloat() >= f.toFloat());
}

bool    Fixed::operator<=(const Fixed& f) const
{
    return (this->toFloat() <= f.toFloat());
}

bool    Fixed::operator==(const Fixed& f) const
{
    return (this->toFloat() == f.toFloat());
}

bool    Fixed::operator!=(const Fixed& f) const
{
    return (this->toFloat() != f.toFloat());
}

// ! arithmetic operators
Fixed Fixed::operator+(const Fixed& f) const
{
    Fixed result(this->toFloat() + f.toFloat());
    return (result);
}

Fixed Fixed::operator-(const Fixed& f) const
{
    Fixed result(this->toFloat() - f.toFloat());
    return (result);
}

Fixed Fixed::operator*(const Fixed& f) const
{
    Fixed result(this->toFloat() * f.toFloat());
    return (result);
}

Fixed Fixed::operator/(const Fixed& f) const
{
    Fixed result(this->toFloat() / f.toFloat());
    return (result);
}

// ! Increament & Decreament
// ? Post-Fix
Fixed   Fixed::operator++()
{
    Fixed   result(*this + (1 / (float)(1 << this->numFracBits)));
    return (result);
}

Fixed   Fixed::operator--()
{
    Fixed   result(*this + (1 / (float)(1 << this->numFracBits)));
    return (result);
}

// ? Pre-Fix

// Fixed&   Fixed::operator++()
// {
//     Fixed   result(*this + (1 / (float)(1 << this->numFracBits)));
//     return (result);
// }

// Fixed&   Fixed::operator--()
// {
//     Fixed   result(*this + (1 / (float)(1 << this->numFracBits)));
//     return (result);
// }