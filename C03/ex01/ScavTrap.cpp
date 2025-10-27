#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap: Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap: Parameterized Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
    std::cout << "ScavTrap: Copy Constructor Called" << std::endl;
}

ScavTrap& ScavTrap::operator =(const ScavTrap& src)
{
    if (this == &src)
        *
    std::cout << "ScavTrap: Assignment operator Called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: Destructor Called" << std::endl;
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap: Gate keeper mode (Active)" << std::endl;

}
