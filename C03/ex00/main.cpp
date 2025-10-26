#include "ClapTrap.hpp"
#include <iostream>

int main() {
    // --- Test 1: Basic functionality ---
    std::cout << "--- 🎬 TEST SCENARIO 1: BASIC ACTIONS ---" << std::endl;
    ClapTrap clappy("CL4P-TP");
    
    clappy.attack("a random Badass");
    clappy.takeDamage(6);
    clappy.beRepaired(4);
    clappy.takeDamage(8);
    
    // --- Test 2: Inability to act when destroyed (0 HP) ---
    std::cout << "\n--- 🎬 TEST SCENARIO 2: NO HIT POINTS ---" << std::endl;
    std::cout << "CL4P-TP should now have 0 HP and be unable to act." << std::endl;
    clappy.attack("the air");   // Should fail
    clappy.beRepaired(10);   // Should fail

    std::cout << std::endl;

    // --- Test 3: Depleting energy and inability to act ---
    std::cout << "\n--- 🎬 TEST SCENARIO 3: NO ENERGY POINTS ---" << std::endl;
    ClapTrap trappy("FR4G-TP");
    
    std::cout << "Depleting FR4G-TP's energy..." << std::endl;
    // Attack 10 times to use all 10 energy points
    for (int i = 0; i < 10; ++i) {
        trappy.attack("a Psycho");
    }

    std::cout << "\nFR4G-TP should now have 0 Energy Points and be unable to act." << std::endl;
    trappy.attack("another Psycho"); // Should fail
    trappy.beRepaired(5);          // Should fail
    trappy.takeDamage(9);          // Taking damage should still work as it's a reaction

    std::cout << "\n--- 🏁 TESTS COMPLETE ---" << std::endl;
    return 0;
}