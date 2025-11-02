#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& src)
{
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
    this->type = src.type;
}

WrongAnimal& WrongAnimal::operator =(const WrongAnimal& src)
{
    std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
    this->type = src.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: Destructor called" << std::endl;
}

// *******
std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void        WrongAnimal::setType(std::string type)
{
    this->type = type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "No Sound" << std::endl;
}
    