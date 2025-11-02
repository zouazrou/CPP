#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(WrongCat& src);
    WrongCat& operator =(const WrongCat& src);
    ~WrongCat();
    
    void makeSound(void) const;
};

#endif 
