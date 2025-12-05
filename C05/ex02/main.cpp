#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "TEST 1: BASIC FORM CREATION & EXCEPTIONS" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    try {
        std::cout << "Attempting to create Form with sign grade 0..." << std::endl;
        Form f1("InvalidForm", 0, 50);
    }
    catch (std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nAttempting to create Form with execute grade 151..." << std::endl;
        Form f2("InvalidForm", 50, 151);
    }
    catch (std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nCreating valid Form (Tax Report)..." << std::endl;
        Form tax("Tax Report", 50, 100);
        
        std::cout << "==Form Info==\n:\n" << tax << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "TEST 2: SIGNING FORMS (Success, Equality, Failure)" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 50);
        Bureaucrat intern("Intern", 150);

        Form contract("Employment Contract", 50, 100);

        std::cout << "==Form Info==\n" << contract << std::endl;

        std::cout << "\n[Boss (Grade 1) attempts to sign]" << std::endl;
        boss.signForm(contract);
        
        Form secretDocs("Secret Docs", 40, 40);

        std::cout << "\n[Manager (Grade 50) attempts to sign 'Secret Docs' (Req: 40)]" << std::endl;
        manager.signForm(secretDocs); // Should print "couldn't sign... because..."

        Form basicForm("Basic Form", 50, 100);
        std::cout << "\n[Manager (Grade 50) attempts to sign 'Basic Form' (Req: 50)]" << std::endl;
        manager.signForm(basicForm); // Should succeed (<= rule)

    }
    catch (std::exception& e) {
        std::cout << "Global Exception: " << e.what() << std::endl;
    }

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "TEST 3: DOUBLE SIGNING (Optional logic check)" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    try {
        Bureaucrat ceo("CEO", 1);
        Form paper("Paper", 10, 10);

        ceo.signForm(paper);
        std::cout << "Trying to sign the same form again..." << std::endl;
        ceo.signForm(paper); 
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}