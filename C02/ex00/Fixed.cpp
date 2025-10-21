#include "Fixed.hpp"

static const int numFracBits = 8;

Fixed::Fixed() : num(0)
{
    std::cout << "Default constructor called" << std::endl;
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
    std::cout << "getRawBits member function called" << std::endl;
    return (num);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->num = raw;
}
