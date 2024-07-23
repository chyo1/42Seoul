#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    private:
        std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const& src);
        PresidentialPardonForm& operator=(PresidentialPardonForm const& src);
        virtual ~PresidentialPardonForm();

        virtual void execute(Bureaucrat const& executor) const;
};

#endif