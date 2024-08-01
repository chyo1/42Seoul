#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const& src) {
    *this = src;
}

Intern& Intern::operator=(Intern const& src) {
	if (this != &src) {
        ;
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm* form = NULL;

    int i;
    for (i = 0; i < 3; i++) {
        if (formName == formNames[i])
            break;
    }
	switch (i){
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw FormNotFound();
			break;
	}
    std::cout << "Intern creates " << formName << std::endl;
    return form;
}

const char* Intern::FormNotFound::what() const throw() {
    return "Form not found";
}