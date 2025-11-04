#include "AMateria.hpp"

AMateria::AMateria()
{
    // std::cout << "AMateria: Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
    // std::cout << "AMateria: Default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& src)
{
    // std::cout << "AMateria: Copy constructor called" << std::endl;
    this->type = src.type;
}

AMateria& AMateria::operator= (const AMateria& src)
{
    // std::cout << "AMateria: Copy assignment operator called" << std::endl;
    if (this != &src)
        this->type = src.type;
    return (*this);
}

AMateria::~AMateria()
{
    // std::cout << "AMateria: Destructor called" << std::endl;
}


// ***********
std::string const &AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter &target)
{
    if (!type.compare("ice"))
        std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
    if (!type.compare("cure"))
        std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

