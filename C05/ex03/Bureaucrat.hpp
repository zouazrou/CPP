#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

// ? Forward Declaration
class AForm;

class Bureaucrat
{
private:
    const std::string   name;
    int                 grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator =(const Bureaucrat& src);
    ~Bureaucrat();

    // **Getters**
    std::string getName(void) const;
    int         getGrade(void) const;

    // **Other Methods**
    void    promote(void);
    void    demote(void);
    void    signForm(AForm& f);
    void    executeForm(AForm const& form) const;

    // **Exception Classes**
    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return ("Grade Too High !");
        }
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return ("Grade Too Low !");
        }
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c);

#endif