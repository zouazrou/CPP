#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
    /* data */
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& src);
    FragTrap& operator =(const FragTrap& src);
    ~FragTrap();
    
    void highFivesGuys(void);
};

#endif // RAG_TRAP_HPP
