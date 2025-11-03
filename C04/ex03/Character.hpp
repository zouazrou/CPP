#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character
{
// ! acces !
    std::string name;
    int         currSize;
    AMateria    *slot[4];
public:
    Character();
    Character(const Character& src);
    Character& operator =(const Character& src);
    // * pure member functions
    ~Character();

    std::string const   &getName() const;
    void                equip(AMateria *m);
    void                unequip(int idx);
    void                use(int idx, Character &target);
};

#endif
