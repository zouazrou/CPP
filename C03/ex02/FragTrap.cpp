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

// *********
void FragTrap::attack(const std::string& target)
{
    if (!getHitPoints())
    {
        std::cout << "hit Points is Empty !" << std::endl;
        return ;
    }
    if (!getEnergyPoints())
    {
        std::cout << "Energy Points is Empty !" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << getName()
              << " attacks " << target
              << ", causing " << getAttackDamage()
              << " points of damage!" << std::endl;
    setEnergyPoints(getEnergyPoints() - 1);
}

void FragTrap::highFivesGuys(void)
{
    if (!getHitPoints())
    {
        std::cout << "Hit Points is Empty !" << std::endl;
        return ;
    }
    if (!getEnergyPoints())
    {
        std::cout << "Energy Points is Empty !" << std::endl;
        return ;
    }
    std::cout << "Can You give me Five?" << std::endl;
}
