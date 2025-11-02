#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog: Default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(Dog& src) : Animal(src)
{
    std::cout << "Dog: Copy constructor called" << std::endl;
    this->type = src.type;
}

Dog& Dog::operator =(const Dog& src)
{
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    if (this != &src)
        Animal::operator=(src);
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor called" << std::endl;
}


void    Dog::makeSound(void) override
{
    std::cout << "Bark !"<< std::endl;
}