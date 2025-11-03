#include "Character.hpp"

Character::Character() : currSize(0)
{
    std::cout << "Character: Default constructor called" << std::endl;
}

Character::Character(const Character& src)
{
    std::cout << "Character: Copy constructor called" << std::endl;
    this->currSize = src.currSize;
    this->name = src.name;
    // ...
}

Character& Character::operator =(const Character& src)
{
    std::cout << "Character: Copy assignment operator constructor called" << std::endl;
    this->currSize = src.currSize;
    this->name = src.name;
    // ...
}

Character::~Character()
{
    std::cout << "Character: destructor called" << std::endl;
}

// * pure member functions

std::string const   &Character::getName() const
{
    return (this->name);
}

void                Character::equip(AMateria *m)
{

}

void                Character::unequip(int idx)
{

}

void                Character::use(int idx, Character &target)
{

}
