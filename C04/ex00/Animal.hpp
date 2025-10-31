#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(Animal& src);
    Animal& operator =(const Animal& src);
    ~Animal();

    std::string getType(void);
    void        setType(std::string type);

    virtual void        makeSound(void);
};

#endif 
