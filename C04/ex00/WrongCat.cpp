#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat: Default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat& src) : WrongAnimal(src)
{
    std::cout << "WrongCat: Copy constructor called" << std::endl;
    this->type = src.type;
}

WrongCat& WrongCat::operator =(const WrongCat& src)
{
    std::cout << "WrongCat: Copy assignment operator called" << std::endl;
    if (this != &src)
        WrongAnimal::operator=(src);
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat: Destructor called" << std::endl;
}

// ************
void    WrongCat::makeSound(void) const
{
    std::cout << "Meooooow !" << std::endl;
}