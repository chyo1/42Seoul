#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(10), _execGrade(10) {}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (_signGrade < 1 || _execGrade < 1) {
        throw AForm::GradeTooHighException();
    } else if (_signGrade > 150 || _execGrade > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(AForm const& src) : _name(src.getName()), _isSigned(src.getIsSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()){}

AForm& AForm::operator=(AForm const& src) {
    if (this != &src) {
        _isSigned = src.getIsSigned();
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade) {
        throw AForm::GradeTooLowException();
    }
    else {
        _isSigned = true;
    }
}


std::ostream& operator<<(std::ostream& os, const AForm& src) {
    os << "AForm: " << src.getName() << ", Sign Grade: " << src.getSignGrade() << ", Exec Grade: " << src.getExecGrade() << ", Signed: " << src.getIsSigned() << std::endl;
    return os;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is Too High";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is Too Low";
}