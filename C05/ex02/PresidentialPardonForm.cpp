#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& s) : AForm(s)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm& s)
{
    if (this != &s)
        AForm::operator=(s);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

// ****

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (this->getIsSign() == false)
        throw FormNotSignedException();
    if (executor.getGrade() > 5)
        throw GradeTooLowException();
    // **Form's Action**
    std::cout << "WWWWWWWWWWWWWWWWWWWWWWWWW" << std::endl;
    
}
