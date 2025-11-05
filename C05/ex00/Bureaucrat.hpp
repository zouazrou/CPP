#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
private:
    const std::string   name;
    int                 grade;
public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator =(const Bureaucrat& src);
    ~Bureaucrat();
    // *****

    std::string getName(void) const;
    int         getGrade(void) const;
};

#endif