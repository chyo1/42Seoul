#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade()) {
    this->_target = src._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& src) {
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned() || executor.getGrade() > getExecGrade()) {
        throw AForm::GradeTooLowException();
    }
    
    srand(time(NULL));
    if (rand() % 2) {
        std::cout << getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
    } else {
        std::cout << getName() << " has not been pardoned by Zafod Beeblebrox." << std::endl;
    }
}