#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    // --- 1. Test Construction ---
    // This will show the ClapTrap constructor running first,
    // followed by the ScavTrap constructor.
    std::cout << "--- CONSTRUCTING 'GORTYS' ---" << std::endl;
    ScavTrap scav("GORTYS");
    std::cout << std::endl;

    // --- 2. Test New & Overridden Functions ---
    // This will show the ScavTrap's unique attack message (20 AD)
    // and its new guardGate() ability.
    std::cout << "--- TESTING ABILITIES ---" << std::endl;
    scav.attack("a Badass Psycho");
    scav.guardGate();
    std::cout << std::endl;

    // --- 3. Test Inherited Functions & Stats ---
    // This shows it still uses ClapTrap's functions, but with
    // its own, larger stat pool (100 HP, 50 EP).
    std::cout << "--- TESTING STATS & INHERITED ABILITIES ---" << std::endl;
    scav.takeDamage(30); // HP: 100 -> 70
    scav.beRepaired(20); // HP: 70 -> 90. EP: 50 -> 49 (after attack) -> 48
    scav.takeDamage(89); // HP: 90 -> 1
    scav.takeDamage(1);  // HP: 1 -> 0
    std::cout << std::endl;

    // --- 4. Test Edge Cases (No HP) ---
    // Functions should fail if the ScavTrap has 0 HP.
    std::cout << "--- TESTING NO-HP EDGE CASE ---" << std::endl;
    scav.attack("a wall"); // Should fail
    scav.beRepaired(10); // Should fail
    scav.guardGate();    // Should probably also fail or be different
    std::cout << std::endl;

    // --- 5. Test Copy ---
    // This will also demonstrate the constructor chain.
    std::cout << "--- TESTING COPY CONSTRUCTOR ---" << std::endl;
    ScavTrap scavCopy(scav);
    std::cout << std::endl;

    // --- 6. Test Destruction ---
    // This will show the destructors running in reverse order:
    // 1. scavCopy (ScavTrap -> ClapTrap)
    // 2. scav (ScavTrap -> ClapTrap)
    std::cout << "--- DESTRUCTING (END OF MAIN) ---" << std::endl;
    return 0;
}