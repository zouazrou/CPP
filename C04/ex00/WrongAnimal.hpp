#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(WrongAnimal& src);
    WrongAnimal& operator =(const WrongAnimal& src);
    virtual ~WrongAnimal();

    std::string getType(void) const;
    void        setType(std::string type);

    void        makeSound(void) const;
};

#endif 
