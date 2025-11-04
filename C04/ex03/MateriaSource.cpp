#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : currSize(0)
{
    // std::cout << "MateriaSource: Default constructor called" << std::endl;
    for (int i = 0; i < NUM_MTR; i++)
    {
        slot[i] = NULL;
    }
    
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    // std::cout << "MateriaSource: Copy constructor called" << std::endl;
    this->currSize = src.currSize;
    for (int i = 0; i < NUM_MTR; i++)
    {
        slot[i] = src.slot[i]->clone();
    }
}

MateriaSource& MateriaSource::operator =(const MateriaSource& src)
{
    // std::cout << "MateriaSource: Copy assignment operator constructor called" << std::endl;
    if (this == &src)
        return (*this);
    this->currSize = src.currSize;
    for (int i = 0; i < NUM_MTR; i++)
    {
        delete slot[i];
        slot[i] = src.slot[i]->clone();
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    // std::cout << "MateriaSource: destructor called" << std::endl;
    for (int i = 0; i < NUM_MTR; i++)
    {
        delete slot[i];
    }
}

// ************

void MateriaSource::learnMateria(AMateria *m)
{
    if (currSize == NUM_MTR || m == NULL)
        return ;
    for (int i = 0; i < NUM_MTR; i++)
    {
        if (!slot[i])
        {
            slot[i] = m->clone();
            currSize++;
            return ;
        }
    }
    
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < NUM_MTR; i++)
    {
        if (!type.compare(slot[i]->getType()))
            return (slot[i]->clone());
    }
    return (0);
}
