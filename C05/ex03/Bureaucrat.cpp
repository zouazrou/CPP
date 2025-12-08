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

// **Other Methods**
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

void    Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << " because " << e.what() << '.' << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const& form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed "
                  << form.getName() << std::endl;
    }
    catch (std::exception& c)
    {
        std::cout << this->getName() << " can't execute "
                  << form.getName() << " form because " 
                  << c.what()
                  << std::endl;
    }
}

// **Getters**
std::string Bureaucrat::getName(void) const
{
    return (this->name);
}

int         Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

// *******

std::ostream& operator<<(std::ostream &out, const Bureaucrat &c)
{
    out << c.getName() << ", bureaucrat grade " << c.getGrade() << ".";
    return (out);
}

// **Exception**
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade Too High !");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low !");
}