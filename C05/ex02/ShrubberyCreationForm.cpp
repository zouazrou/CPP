#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s) : AForm(s)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator =(const ShrubberyCreationForm& s)
{
    if (this != &s)
        AForm::operator=(s);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// ****

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (this->getIsSign() == false)
        throw FormNotSignedException();
    if (executor.getGrade() > 137)
        throw GradeTooLowException();
    // **Form's Action**
    std::cout << "XXXXXXXXXXXXXXXXXXXXXXX" << std::endl;
}
