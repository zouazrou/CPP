#include "cure.hpp"

cure::cure() : AMateria("cure")
{
    std::cout << "cure: Default constructor called" << std::endl;
}

cure::cure(const cure& src)
{
    std::cout << "cure: Copy constructor called" << std::endl;
}

cure& cure::operator =(const cure& src)
{
    std::cout << "cure: Copy assignment operator constructor called" << std::endl;
}

cure::~cure()
{
    std::cout << "cure: destructor called" << std::endl;
}

// *********
AMateria*   cure::clone() const
{
    return new cure();
}

void        cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.name << "'s wounds *" << std::endl;
}