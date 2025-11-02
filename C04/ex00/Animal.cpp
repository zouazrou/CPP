#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(Animal& src)
{
    std::cout << "Animal: Copy constructor called" << std::endl;
    this->type = src.type;
}

Animal& Animal::operator =(const Animal& src)
{
    std::cout << "Animal: Copy assignment operator called" << std::endl;
    this->type = src.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal: Destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void        Animal::setType(std::string type)
{
    this->type = type;
}

void Animal::makeSound(void)
{
    std::cout << "No Sound" << std::endl;
}
    