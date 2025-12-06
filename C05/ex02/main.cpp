#include <iostream>
#include <cstdlib> // For rand/srand
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Colors for readable output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void printHeader(std::string title) {
    std::cout << "\n" << YELLOW << "---------------------------------------" << RESET << std::endl;
    std::cout << YELLOW << title << RESET << std::endl;
    std::cout << YELLOW << "---------------------------------------" << RESET << std::endl;
}

int main() {
    // Seed random number generator for Robotomy
    std::srand(time(NULL));

    // -------------------------------------------------------------------------
    // TEST 1: ShrubberyCreationForm
    // Requirements: Sign 145, Exec 137
    // -------------------------------------------------------------------------
    printHeader("TEST 1: ShrubberyCreationForm (Garden)");
    try {
        Bureaucrat  bob("Gardener Bob", 130); // Grade 130 is enough for both
        ShrubberyCreationForm shrub("home");

        std::cout << BLUE << "[INFO] " << RESET << bob << std::endl;
        std::cout << BLUE << "[INFO] " << RESET << std::endl;
        std::cout << shrub << std::endl;

        // Try to execute before signing (Should fail)
        std::cout << BLUE << "[TEST] Executing before signing:" << RESET << std::endl;
        bob.executeForm(shrub); 

        // Sign
        std::cout << BLUE << "\n[TEST] Signing form:" << RESET << std::endl;
        bob.signForm(shrub);

        // Execute (Should succeed and create 'home_shrubbery')
        std::cout << BLUE << "\n[TEST] Executing form:" << RESET << std::endl;
        bob.executeForm(shrub);
        std::cout << GREEN << "[CHECK] Check your directory for 'home_shrubbery' file." << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    // ! -------------------------------------------------------------------------
    // TEST 2: RobotomyRequestForm
    // Requirements: Sign 72, Exec 45
    // -------------------------------------------------------------------------
    printHeader("TEST 2: RobotomyRequestForm (RoboCop)");
    try {
        Bureaucrat  cop("RoboCop", 40); // Grade 40 is enough
        RobotomyRequestForm robot("Bender");

        std::cout << BLUE << "[INFO] " << RESET << cop << std::endl;
        std::cout << BLUE << "[INFO] " << RESET << std::endl;
        std::cout << robot << std::endl;

        cop.signForm(robot);
        
        std::cout << BLUE << "\n[TEST] Executing 4 times to check 50% probability:" << RESET << std::endl;
        // Run multiple times to see success and failure messages
        for (int i = 0; i < 4; i++) {
            std::cout << "Attempt " << i + 1 << ": ";
            cop.executeForm(robot);
            std::cout << "----------------" << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 3: PresidentialPardonForm
    // Requirements: Sign 25, Exec 5
    // -------------------------------------------------------------------------
    printHeader("TEST 3: PresidentialPardonForm (Zaphod)");
    try {
        Bureaucrat  president("Mr. President", 4); // Grade 4 is super high
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << BLUE << "[INFO] " << RESET << president << std::endl;
        std::cout << BLUE << "[INFO] " << RESET << std::endl;
        std::cout << pardon << std::endl;

        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 4: NEGATIVE TESTS (Grade too low to Execute)
    // -------------------------------------------------------------------------
    printHeader("TEST 4: Failure Scenarios - Grade too low to execute");
    try {
        // Can sign (145) but cannot execute (137)
        Bureaucrat  intern("Intern", 140); 
        ShrubberyCreationForm shrub("office");

        std::cout << BLUE << "[INFO] " << RESET << intern << std::endl;
        std::cout << BLUE << "[INFO] " << RESET << std::endl;
        std::cout << shrub << std::endl;

        std::cout << BLUE << "\n[TEST] Signing:" << RESET << std::endl;
        intern.signForm(shrub); // Should work

        std::cout << BLUE << "\n[TEST] Executing (Should Fail):" << RESET << std::endl;
        intern.executeForm(shrub); // Should throw GradeTooLow
    }
    catch (std::exception &e) {
        std::cout << GREEN << "Expected Exception caught: " << e.what() << RESET << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 5: NEGATIVE TESTS (Unsigned Form)
    // -------------------------------------------------------------------------
    printHeader("TEST 5: Failure Scenarios - Unsigned Form");
    try {
        Bureaucrat  boss("Boss", 1); 
        PresidentialPardonForm pardon("Criminal");

        std::cout << BLUE << "[INFO] " << RESET << boss << std::endl;
        std::cout << BLUE << "[TEST] Executing without signing (Should Fail):" << RESET << std::endl;
        
        // We purposely do NOT call boss.signForm(pardon)
        boss.executeForm(pardon); 
    }
    catch (std::exception &e) {
        std::cout << GREEN << "Expected Exception caught: " << e.what() << RESET << std::endl;
    }
    return 0;
}