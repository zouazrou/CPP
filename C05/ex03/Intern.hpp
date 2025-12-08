#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define NUM_TYPE 3

class Intern
{
private:
    typedef AForm* (*PtrFunction)(const std::string&);

    static  std::string nameForms[];
    static  PtrFunction FormsCreators[];

    static  AForm   *makePresidentialPardonForm(const std::string& target);
    static  AForm   *makeRobotomyRequestForm(const std::string& target);
    static  AForm   *makeShrubberyCreationForm(const std::string& target);
public:
    Intern();
    Intern(const Intern& s);
    Intern operator =(const Intern& s);
    ~Intern();

    AForm   *makeForm(const std::string& formName, const std::string& target);
};

#endif
