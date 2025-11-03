#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class ice : public AMateria
{
public:
    ice();
    ice(const ice& src);
    ice& operator =(const ice& src);
    ~ice();

    // ********
    AMateria    *clone() const;
    void        use(ICharacter &target);

};

#endif
