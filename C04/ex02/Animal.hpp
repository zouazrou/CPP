#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& src);
    Animal& operator =(const Animal& src);
    virtual ~Animal();

    std::string getType(void) const;
    void        setType(std::string type);

    virtual void        makeSound(void) const = 0;
};

#endif 
