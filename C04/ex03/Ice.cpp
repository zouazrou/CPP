#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "Ice: Default constructor called" << std::endl;
}

Ice::Ice(const Ice& src) : AMateria(src)
{
    // std::cout << "Ice: Copy constructor called" << std::endl;
    if (this != &src)
    {
        this->type = src.getType();
    }
}

Ice& Ice::operator =(const Ice& src)
{
    // std::cout << "Ice: Copy assignment operator constructor called" << std::endl;
    if (this != &src)
    {
        AMateria::operator=(src);
        this->type = src.getType();
    }
    return (*this);
}

Ice::~Ice()
{
    // std::cout << "Ice: destructor called" << std::endl;
}

// *********
AMateria* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an Ice bolt at " << target.getName() << std::endl;
}