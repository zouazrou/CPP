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
    AForm& operator =(const AForm& src);
    virtual ~AForm();

    // **Getters**
    std::string     getName(void) const;
    bool            getIsSign(void) const;
    int             getGradeToSign(void) const;
    int             getGradeToExec(void) const;

    // **Utils**
    void            beSigned(const Bureaucrat& Person);
    virtual void    execute(Bureaucrat const& executor) const = 0;

    // **Exception Classes**
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &c);

#endif