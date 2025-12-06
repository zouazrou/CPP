#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

// ? Forward Declaration
class Bureaucrat;

class Form
{
private:
    const std::string   name;
    bool                isSigned;
    const int           gradeToSign;
    const int           gradeToExec;
public:
    Form();
    Form(const Form& src);
    Form(const std::string& name, const int toSign, const int toExec);
    Form& operator =(const Form& src);
    ~Form();

    // **Getters**
    std::string     getName(void) const;
    bool            getIsSign(void) const;
    int             getGradeToSign(void) const;
    int             getGradeToExec(void) const;

    // **Utils**
    void    beSigned(const Bureaucrat& Person);

    // **Exception Classes**
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return ("Grade is too high !");
        }
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return ("Grade is too low !");
        }
    };
};

std::ostream &operator<<(std::ostream &out, const Form &c);

#endif