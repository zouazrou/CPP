#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog: Default constructor called" << std::endl;
    this->type = "Dog";
    this->BrainPtr = new Brain();
}

Dog::Dog(const Dog& src) : Animal(src)
{
    std::cout << "Dog: Copy constructor called" << std::endl;
    this->type = src.type;
    this->BrainPtr = new Brain();
    *this->BrainPtr = *src.BrainPtr;
}

Dog& Dog::operator =(const Dog& src)
{
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        Animal::operator=(src);
        *this->BrainPtr = *src.BrainPtr;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor called" << std::endl;
    delete this->BrainPtr;
    // this->BrainPtr = NULL;
}

// ********
void    Dog::makeSound(void) const
{
    std::cout << "Bark !" << std::endl;
    
}