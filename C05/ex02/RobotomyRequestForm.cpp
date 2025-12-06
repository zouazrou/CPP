#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s) : AForm(s)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator =(const RobotomyRequestForm& s)
{
    if (this != &s)
        AForm::operator=(s);
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
    std::cout << "YYYYYYYYYYYYYYYYYYYYYYYYYY" << std::endl;
}
