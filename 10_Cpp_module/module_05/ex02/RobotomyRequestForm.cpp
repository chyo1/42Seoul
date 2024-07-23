#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade()){
    this->_target = src._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& src) {
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned() || executor.getGrade() > getExecGrade()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << " *drilling noises* " << std::endl;
    std::cout << _target << " has been robotomized successfully 50\% of the time." << std::endl;
}