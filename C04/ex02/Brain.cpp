#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
    std::cout << "Brain: Copy constructor called" << std::endl;
    for (size_t i = 0; i < SIZE_ARR; i++)
        this->ideas[i] = src.ideas[i];
}

Brain& Brain::operator =(const Brain& src)
{
    std::cout << "Brain: Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        for (size_t i = 0; i < SIZE_ARR; i++)
            this->ideas[i] = src.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain: Destructor called" << std::endl;
}
