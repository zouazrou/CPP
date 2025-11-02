#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat: Default constructor called" << std::endl;
    this->type = "Cat";
    this->BrainPtr = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src)
{
    std::cout << "Cat: Copy constructor called" << std::endl;
    this->type = src.type;
    this->BrainPtr = new Brain();
}

Cat& Cat::operator =(const Cat& src)
{
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    if (this != &src)
        Animal::operator=(src);
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor called" << std::endl;
    delete this->BrainPtr;
    // this->BrainPtr = NULL;
}

// ************
void    Cat::makeSound(void) const
{
    std::cout << "Meooooow !" << std::endl;
}