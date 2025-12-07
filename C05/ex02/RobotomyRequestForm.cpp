#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s) : AForm(s), target(s.target)
{
    srand(time(NULL));
}

RobotomyRequestForm& RobotomyRequestForm::operator =(const RobotomyRequestForm& s)
{
    if (this != &s)
    {
        this->target = s.target;
        AForm::operator=(s);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

// ****

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    int val;
    if (this->getIsSign() == false)
        throw FormNotSignedException();
    if (executor.getGrade() > 45)
        throw GradeTooLowException();
    // **Form's Action**
    val = rand() % 2;
    if (val)
        std::cout << target << ": has been robotomized successfully" << std::endl;
    else
        std::cout << target << ": the robotomy failed" << std::endl;
}
