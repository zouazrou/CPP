#include "ice.hpp"

ice::ice() : AMateria("ice")
{
    std::cout << "ice: Default constructor called" << std::endl;
}

ice::ice(const ice& src)
{
    std::cout << "ice: Copy constructor called" << std::endl;
}

ice& ice::operator =(const ice& src)
{
    std::cout << "ice: Copy assignment operator constructor called" << std::endl;
}

ice::~ice()
{
    std::cout << "ice: destructor called" << std::endl;
}

// *********
AMateria* ice::clone() const
{
    return new ice();
}

void ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.name << std::endl;
}