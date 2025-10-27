#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    std::cout << "--- CONSTRUCTING 'GORTYS' ---" << std::endl;
    ScavTrap scav("GORTYS");
    std::cout << std::endl;

    std::cout << "--- TESTING ABILITIES (OVERRIDDEN ATTACK + GUARD) ---" << std::endl;
    scav.attack("a Badass Psycho");
    scav.guardGate();
    std::cout << std::endl;

    std::cout << "--- TESTING INHERITED METHODS & STATS ---" << std::endl;
    scav.takeDamage(30);    // 100 -> 70
    scav.beRepaired(20);    // 70 -> 90, EP 50 -> 49
    scav.attack("a Skag");  // EP 49 -> 48
    std::cout << std::endl;

    std::cout << "--- TESTING NO-HP EDGE CASE ---" << std::endl;
    scav.takeDamage(89);    // 90 -> 1
    scav.takeDamage(1);     // 1 -> 0
    scav.attack("a wall");  // should fail: no HP
    scav.beRepaired(10);    // should fail: no HP
    scav.guardGate();       // still prints mode message
    std::cout << std::endl;

    std::cout << "--- TESTING NO-EP EDGE CASE ---" << std::endl;
    ScavTrap tired("TIRED");
    for (int i = 0; i < 50; ++i) tired.attack("dummy"); // drain EP to 0
    tired.attack("another dummy"); // should fail: no EP
    std::cout << std::endl;

    std::cout << "--- TESTING COPY CONSTRUCTOR ---" << std::endl;
    ScavTrap scavCopy(scav);   // copies 0 HP state
    scavCopy.attack("anything"); // should fail due to 0 HP
    std::cout << std::endl;

    std::cout << "--- TESTING ASSIGNMENT OPERATOR ---" << std::endl;
    ScavTrap a("A");
    ScavTrap b("B");
    a.takeDamage(100);          // A to 0 HP
    b = a;                      // B now also 0 HP
    b.attack("target");         // should fail due to 0 HP
    std::cout << std::endl;

    std::cout << "--- DESTRUCTING (END OF MAIN) ---" << std::endl;
    return 0;
}