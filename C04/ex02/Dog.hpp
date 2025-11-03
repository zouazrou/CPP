#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain   *ptrBrain;
public:
    Dog();
    Dog(const Dog& src);
    Dog& operator =(const Dog& src);
    ~Dog();

    void makeSound(void) const;
};

#endif 
