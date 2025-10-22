#include "Fixed.hpp"

const int Fixed::numFracBits = 8;

Fixed::Fixed() : num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(num * pow(2, numFracBits));
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    setRawBits(num * pow(2, numFracBits));
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
    return (getRawBits() / pow(2, numFracBits));
}