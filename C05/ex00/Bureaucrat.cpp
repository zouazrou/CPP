#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150)
{}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
    this->grade = src.grade;
}

Bureaucrat& Bureaucrat::operator =(const Bureaucrat& src)
{
    if (this != &src)
        this->grade = src.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{}

// *******
std::ostream& operator<<(std::ostream &out, const Bureaucrat &c)
{
    out << c.getName() << ", bureaucrat grade " << c.getGrade() << ".";
    return (out);
}

void    Bureaucrat::promote()
{
    if (this->grade == 1)
        throw GradeTooHighException();
    else
        this->grade -= 1;
}

void    Bureaucrat::demote()
{
    if (this->grade == 150)
        throw GradeTooLowException();
    else
        this->grade += 1;
}

std::string Bureaucrat::getName(void) const
{
    return (this->name);
}

int         Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

// **Exceptions**

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade Too High !");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low !");
}