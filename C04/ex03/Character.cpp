#include "Character.hpp"

Character::Character() : currSize(0)
{
    // std::cout << "Character: Default constructor called" << std::endl;
    for (int i = 0; i < NUM_MTR; i++)
        this->slot[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
    // std::cout << "Character: Param constructor called" << std::endl;
    this->currSize = 0;
    for (int i = 0; i < NUM_MTR; i++)
    {
        this->slot[i] = NULL;
    }
}

Character::Character(const Character& src)
{
    // std::cout << "Character: Copy constructor called" << std::endl;
    this->currSize = src.currSize;
    this->name = src.name;
    for (int i = 0; i < NUM_MTR; i++)
    {
        this->slot[i] = src.slot[i]->clone();
    }
}

Character& Character::operator =(const Character& src)
{
    // std::cout << "Character: Copy assignment operator constructor called" << std::endl;
    if (this == &src)
        return (*this);
    this->currSize = src.currSize;
    this->name = src.name;
    for (int i = 0; i < NUM_MTR; i++)
    {
        delete this->slot[i];
        this->slot[i] = src.slot[i]->clone();
    }
    return (*this);
}

Character::~Character()
{
    // std::cout << "Character: destructor called" << std::endl;
    for (int i = 0; i < NUM_MTR; i++)
    {
        delete this->slot[i];
    }
}

// * pure member functions

std::string const   &Character::getName() const
{
    return (this->name);
}

void                Character::equip(AMateria *m)
{
    if (currSize == NUM_MTR || m == NULL)
        return ;
    for (int i = 0; i < NUM_MTR; i++)
    {
        if (!slot[i])
        {
            this->slot[i] = m;
            currSize++;
            return ;
        }
    }
    
}

void                Character::unequip(int idx)
{
    if (idx > -1 && idx < currSize)
    {
        slot[idx] = NULL;
        currSize--;
    }
}

void                Character::use(int idx, ICharacter &target)
{
    if (idx > -1 && idx < currSize && slot[idx])
        slot[idx]->use(target);
}
