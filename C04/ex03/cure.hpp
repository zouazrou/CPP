#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class cure : public AMateria
{
public:
    cure();
    cure(const cure& src);
    cure& operator =(const cure& src);
    ~cure();

    // ********
    AMateria    *clone() const;
    void        use(ICharacter &target);

};

#endif
