#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(Cat& src);
    Cat& operator =(const Cat& src);
    ~Cat();
    
    void makeSound(void) const;
};

#endif 
