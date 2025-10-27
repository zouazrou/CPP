#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap: Default Constructor Called" << std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap: Parameterized Constructor Called" << std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
    std::cout << "FragTrap: Copy Constructor Called" << std::endl;
}

FragTrap& FragTrap::operator =(const FragTrap& src)
{
    if (this != &src)
        ClapTrap::operator=(src);
    std::cout << "FragTrap: Assignment operator Called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap: Destructor Called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << << std::enld;
}
