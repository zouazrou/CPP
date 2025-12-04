#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- TEST 1: Standard Constructors ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 1);
        std::cout << bob << std::endl; // Should print 1

        Bureaucrat alice("Alice", 150);
        std::cout << alice << std::endl; // Should print 150
    }
    catch (std::exception &e) {
        std::cerr << "Test 1 Failed: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Constructor Limits (Too High) ---" << std::endl;
    try {
        Bureaucrat godMode("God", 0); // Should THROW
        std::cout << "FAIL: Created grade 0!" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "SUCCESS caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: Constructor Limits (Too Low) ---" << std::endl;
    try {
        Bureaucrat peasant("Peasant", 151); // Should THROW
        std::cout << "FAIL: Created grade 151!" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "SUCCESS caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: Increment/Decrement Operations ---" << std::endl;
    try {
        Bureaucrat worker("Worker", 2);
        std::cout << "Before: " << worker << std::endl;
        
        worker.promote(); // 2 -> 1
        std::cout << "After Increment: " << worker << std::endl;

        worker.demote(); // 1 -> 2
        std::cout << "After Decrement: " << worker << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Test 4 Failed: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 5: Increment out of bounds ---" << std::endl;
    try {
        Bureaucrat best("Best", 1);
        std::cout << "Current: " << best << std::endl;
        best.promote(); // Should THROW (1 -> 0 is invalid)
        std::cout << "FAIL: Incremented beyond 1!" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "SUCCESS caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 6: Decrement out of bounds ---" << std::endl;
    try {
        Bureaucrat worst("Worst", 150);
        std::cout << "Current: " << worst << std::endl;
        worst.demote(); // Should THROW (150 -> 151 is invalid)
        std::cout << "FAIL: Decremented beyond 150!" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "SUCCESS caught: " << e.what() << std::endl;
    }

    return 0;
}