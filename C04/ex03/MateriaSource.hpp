#ifndef MATERIASOURCE
# define MATERIASOURCE

#define NUM_MTR 4

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    int         currSize;
    AMateria    *slot[NUM_MTR];
public:
    MateriaSource();
    MateriaSource(const MateriaSource& src);
    MateriaSource& operator =(const MateriaSource& src);
    ~MateriaSource();

    // ****
    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const &type);
};

#endif 