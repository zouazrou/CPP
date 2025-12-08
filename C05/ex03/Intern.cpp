#include "Intern.hpp"

std::string Intern::nameForms[] = 
{
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

Intern::PtrFunction Intern::FormsCreators[] = 
{
    &Intern::makeShrubberyCreationForm,
    &Intern::makeRobotomyRequestForm,
    &Intern::makePresidentialPardonForm
};

Intern::Intern()
{
}

Intern::Intern(const Intern& s)
{
    (void)s;
}

Intern Intern::operator =(const Intern& s)
{
    (void)s;
    return *this;
}

Intern::~Intern()
{}
// *******

AForm  *Intern::makePresidentialPardonForm(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

AForm     *Intern::makeRobotomyRequestForm(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

AForm   *Intern::makeShrubberyCreationForm(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

// *******
AForm   *Intern::makeForm(const std::string& formName, const std::string& target)
{
    int i = -1;

    while (++i < NUM_TYPE)
    {
        if (formName == nameForms[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (Intern::FormsCreators[i](target));
        }
    }
    if (i == NUM_TYPE)
        std::cout << "This form does not exist!" << std::endl; 
    return (NULL);
}

