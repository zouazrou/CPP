#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() 
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{

}

Bureaucrat& Bureaucrat::operator =(const Bureaucrat& src)
{

}

Bureaucrat::~Bureaucrat()
{

}
// *******

std::string Bureaucrat::getName(void) const
{
    return (this->name);
}

int         Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

// *******

