#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int main()
{
    Intern someRandomIntern;
    AForm *form;
    Bureaucrat Boss("Zakaria", 70);

    // List of form names to test
    std::string targets[] = {"robotomy request", "presidential pardon", "shrubbery creation", "wrong form"};

    for (int i = 0; i < 4; i++)
    {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Attempting to create: " << targets[i] << std::endl;
        form = someRandomIntern.makeForm(targets[i], "Target_X");
        if (form)
        {
            std::cout << GREEN << "SUCCESS: " << form->getName() << " was created at address " << form << RESET << std::endl;
            try
            {
                form->beSigned(Boss);
                std::cout << GREEN << "--->Boss sign this form Succesfully!" << RESET << std::endl;
                try
                {
                    form->execute(Boss);
                    std::cout << GREEN << "--->Boss execute this form Succesfully!" << RESET << std::endl;
                }
                catch(const std::exception &e)
                {
                std::cerr << RED << "--->Boss can't execute this form because : " << e.what() << RESET << std::endl;
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << RED << "--->Boss can't sign this form because : " << e.what() << RESET << std::endl;
            }
            delete form;
        }
        else
            std::cout << RED << "FAILED: Form was not created (returned NULL)." << RESET << std::endl;
    }
    return 0;
}
