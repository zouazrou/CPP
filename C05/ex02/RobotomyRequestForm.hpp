#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& s);
    RobotomyRequestForm& operator =(const RobotomyRequestForm& s);
    ~RobotomyRequestForm();

    virtual void    execute(Bureaucrat const& executor) const;
};

#endif