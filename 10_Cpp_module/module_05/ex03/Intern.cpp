#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const& src) {
    *this = src;
}

Intern& Intern::operator=(Intern const& src) {
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string formName, std::string target) {
    if (formName == "shrubbery creation") {
        return new ShrubberyCreationForm(target);
    } else if (formName == "robotomy request") {
        return new RobotomyRequestForm(target);
    } else if (formName == "presidential pardon") {
        return new PresidentialPardonForm(target);
    } else {
        throw Intern::FormNotFound();
    }
    std::cout << "Intern creates " << formName << std::endl;
}

const char* Intern::FormNotFound::what() const throw() {
    return "Form not found";
}