#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    // std::cout << "Cure: Default constructor called" << std::endl;
}

Cure::Cure(const Cure& src) : AMateria(src)
{
    // std::cout << "Cure: Copy constructor called" << std::endl;
    if (this != &src)
    {
        this->type = src.getType();
    }
}

Cure& Cure::operator =(const Cure& src)
{
    // std::cout << "Cure: Copy assignment operator constructor called" << std::endl;
    if (this != &src)
    {
        AMateria::operator=(src);
        this->type = src.getType();
    }
    return (*this);
}

Cure::~Cure()
{
    // std::cout << "Cure: destructor called" << std::endl;
}

// *********
AMateria*   Cure::clone() const
{
    return new Cure();
}

void        Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}