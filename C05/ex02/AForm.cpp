#include "AForm.hpp"

AForm::AForm() : name(""), isSigned(false), gradeToSign(150), gradeToExec(150) 
{
}

AForm::AForm(const std::string& name, const int toSign, const int toExec) : name(name), isSigned(false), gradeToSign(toSign), gradeToExec(toExec)
{
    if (toSign < 1 || toExec < 1)
        throw AForm::GradeTooHighException();
    if (toSign > 150 || toExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src) : name(src.name), isSigned(false), gradeToSign(src.gradeToSign), gradeToExec(src.gradeToExec)
{
}

AForm& AForm::operator =(const AForm& src)
{
    (void)src;
    return (*this);
}

AForm::~AForm()
{
}

// **Utils**
void    AForm::beSigned(const Bureaucrat& Person)
{
    if (Person.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();
    else
        this->isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &c)
{
    out << "* AForm Name                   : " << c.getName()
        << "\n* Grade required to sign it    : " << c.getGradeToSign()
        << "\n* Grade required to execute it : " << c.getGradeToExec()
        << "\n* Is Signed                    : " << (c.getIsSign() == false ? "No" : "Yes")
        << std::endl;
    return (out);
}


// **Getters**
std::string     AForm::getName(void) const
{
    return (this->name);
}

bool            AForm::getIsSign(void) const
{
    return (this->isSigned);
}

int             AForm::getGradeToSign(void) const
{
    return (this->gradeToSign);
}

int             AForm::getGradeToExec(void) const
{
    return (this->gradeToExec);
}

// **Exception**

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high !");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low !");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form does not signed yet!");
}