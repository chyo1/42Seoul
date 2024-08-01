#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(Intern const& src);
        virtual ~Intern();
        Intern& operator=(Intern const& src);

        AForm* makeForm(std::string formName, std::string target);

        class FormNotFound : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif