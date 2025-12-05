#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

// ? Forward Declaration
class Bureaucrat;

class AForm
{
private:
    const std::string   name;
    bool                isSigned;
    const int           gradeToSign;
    const int           gradeToExec;
public:
    AForm();
    AForm(const AForm& src);
    AForm(const std::string& name, const int toSign, const int toExec);
    const AForm operator =(const AForm& src);
    virtual ~AForm() = 0;

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

std::ostream &operator<<(std::ostream &out, const AForm &c);

#endif