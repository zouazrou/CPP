#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
    std::string name;
    int         hitPoints;
    int         energyPoints;
    int         attackDamage;
public:
    // * Orthodox form
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& c);
    ClapTrap& operator =(const ClapTrap& c);
    ~ClapTrap();

    // *
    void        attack(const std::string& target);
    void        takeDamage(unsigned int amount);
    void        beRepaired(unsigned int amount);

    std::string getName(void);
    int         getHitPoints(void);
    int         getEnergyPoints(void);
    int         getAttackDamage(void);

    void        setName(std::string name);
    void        setHitPoints(int value);
    void        setEnergyPoints(int value);
    void        setAttackDamage(int value);
};

#endif