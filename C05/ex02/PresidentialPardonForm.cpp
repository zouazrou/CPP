#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& s) : AForm(s), target(s.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm& s)
{
    if (this != &s)
    {
        this->target = s.target;
        AForm::operator=(s);
    }
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
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
