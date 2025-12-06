#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& s);
    PresidentialPardonForm& operator =(const PresidentialPardonForm& s);
    ~PresidentialPardonForm();

    virtual void    execute(Bureaucrat const& executor) const;
};

#endif