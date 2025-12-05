#include "Form.hpp"

Form::Form() : name(""), isSigned(false), gradeToSign(150), gradeToExec(150) 
{}

Form::Form(std::string name, const int toSign, const int toExec) : name(name), isSigned(false), gradeToSign(toSign), gradeToExec(toExec)
{
    if (toSign < 1 || toExec < 1)
        throw Form::GradeTooHighException();
    if (toSign > 150 || toExec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& src) : name(src.name), isSigned(false), gradeToSign(src.gradeToSign), gradeToExec(src.gradeToExec)
{}

const Form Form::operator =(const Form& src)
{
    (void)src;
    return (*this);
}

Form::~Form()
{}

// **Utils**
void    Form::beSigned(const Bureaucrat& Person)
{
    if (Person.getGrade() > this->getGradeToSign())
        throw Form::GradeTooLowException();
    else
        this->isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &c)
{
    out << "* Form Name                    : " << c.getName()
        << "\n* Grade required to sign it    : " << c.getGradeToSign()
        << "\n* Grade required to execute it : " << c.getGradeToExec()
        << "\n* Is Signed                    : " << (c.getIsSign() == false ? "No" : "Yes")
        << std::endl;
    return (out);
}


// **Getters**
std::string     Form::getName(void) const
{
    return (this->name);
}

bool            Form::getIsSign(void) const
{
    return (this->isSigned);
}

int             Form::getGradeToSign(void) const
{
    return (this->gradeToSign);
}

int             Form::getGradeToExec(void) const
{
    return (this->gradeToExec);
}

