#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s) : AForm(s), target(s.target)
{
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
    if (this->getIsSign() == false)
        throw FormNotSignedException();
    if (executor.getGrade() > 45)
        throw GradeTooLowException();
    // **Form's Action**
    std::cout << "Click here -> https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c" << std::endl;
}
