#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog: Default constructor called" << std::endl;
    this->type = "Dog";
    this->ptrBrain = new Brain();
}

Dog::Dog(const Dog& src) : Animal(src)
{
    std::cout << "Dog: Copy constructor called" << std::endl;
    this->ptrBrain = new Brain();
    *this->ptrBrain = *src.ptrBrain;
}

Dog& Dog::operator =(const Dog& src)
{
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        Animal::operator=(src);
        *this->ptrBrain = *src.ptrBrain;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor called" << std::endl;
    delete this->ptrBrain;
}


void    Dog::makeSound(void) const
{
    std::cout << "Bark !"<< std::endl;
}