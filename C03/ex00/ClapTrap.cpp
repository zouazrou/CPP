#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->name = "anonymous";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap: Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    // ! the robot's health
    this->hitPoints = 10;
    // ! It's the energy it needs to perform special actions
    this->energyPoints = 10;
    // ! the robot's offensive power
    this->attackDamage = 0;
    std::cout << "ClapTrap: Parameterized Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
{
    this->name = c.name;
    this->hitPoints = c.hitPoints;
    this->energyPoints = c.energyPoints;
    this->attackDamage = c.attackDamage;
    std::cout << "ClapTrap: Copy Constructor Called" << std::endl;
}

ClapTrap& ClapTrap::operator =(const ClapTrap& c)
{
    this->name = c.name;
    this->hitPoints = c.hitPoints;
    this->energyPoints = c.energyPoints;
    this->attackDamage = c.attackDamage;
    std::cout << "ClapTrap: Assignment operator Called" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap: Destructor Called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (!this->hitPoints)
    {
        std::cout << "hit Points is Empty !" << std::endl;
        return ;
    }
    if (!this->energyPoints)
    {
        std::cout << "Energy Points is Empty !" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name
              << " attacks " << target
              << ", causing " << this->attackDamage
              << " points of damage!" << std::endl;
    this->energyPoints--;
}
    
void    ClapTrap::takeDamage(unsigned int amount)
{
    if ((int)amount > this->hitPoints)
        amount = (unsigned int)this->hitPoints;
    this->hitPoints -= amount;
    std::cout << "ClapTrap " << this->name
              << " loses " << amount
              << " HitPoints!" << std::endl;
}
    
void    ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->hitPoints)
    {
        std::cout << "hit Points is Empty !" << std::endl;
        return ;
    }
    if (!this->energyPoints)
    {
        std::cout << "Energy Points is Empty !" << std::endl;
        return ;
    }
    this->hitPoints += amount;
    this->energyPoints--;
    std::cout << "ClapTrap "
              << this->name
              << " has been repaired by "
              << amount
              << std::endl;
}

// ********encapsulation***********
std::string ClapTrap::getName(void)
{
    return (this->name);
}

int         ClapTrap::getHitPoints(void)
{
    return (this->hitPoints);
}

int         ClapTrap::getEnergyPoints(void)
{
    return (this->energyPoints);
}

int         ClapTrap::getAttackDamage(void)
{
    return (this->attackDamage);
}

void        ClapTrap::setName(std::string name)
{
    this->name = name;
}

void        ClapTrap::setHitPoints(int value)
{
    this->hitPoints = value;
}

void        ClapTrap::setEnergyPoints(int value)
{
    this->energyPoints = value;
}

void        ClapTrap::setAttackDamage(int value)
{
    this->attackDamage = value;
}
