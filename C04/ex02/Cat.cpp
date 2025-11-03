#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat: Default constructor called" << std::endl;
    this->type = "Cat";
    this->ptrBrain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src)
{
    std::cout << "Cat: Copy constructor called" << std::endl;
    this->ptrBrain = new Brain();
    *this->ptrBrain = *src.ptrBrain;
}

Cat& Cat::operator =(const Cat& src)
{
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        Animal::operator=(src);
        *this->ptrBrain = *src.ptrBrain;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor called" << std::endl;
    delete this->ptrBrain;
}

// ************
void    Cat::makeSound(void) const
{
    std::cout << "Meooooow !" << std::endl;
}