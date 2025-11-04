#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#define NUM_MTR 4

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string name;
    int         currSize;
    AMateria    *slot[NUM_MTR];
public:
    Character();
    Character(std::string name);
    Character(const Character& src);
    Character& operator =(const Character& src);
    // * pure member functions
    ~Character();

    std::string const   &getName() const;
    void                equip(AMateria *m);
    void                unequip(int idx);
    void                use(int idx, ICharacter &target);
};

#endif
