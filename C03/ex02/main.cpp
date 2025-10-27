#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    FragTrap obj("zakaria");

    obj.attack("l3do");
    obj.highFivesGuys();
    obj.takeDamage(99);
    for (int i = 0; i < 100; i++)
        obj.attack("l3do");
    obj.takeDamage(100);
    obj.takeDamage(100);
    return 0;
}