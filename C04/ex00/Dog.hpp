#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(Dog& src);
    Dog& operator =(const Dog& src);
    ~Dog();

    void makeSound(void);
};

#endif 
