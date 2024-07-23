#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const& src);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const& src);
        virtual ~ShrubberyCreationForm();

        virtual void execute(Bureaucrat const& executor) const;

};

#endif