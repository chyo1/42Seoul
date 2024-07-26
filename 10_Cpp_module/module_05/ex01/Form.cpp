#include "Form.hpp"

#include <iostream>
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(10), _execGrade(10) {}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (_signGrade < 1 || _execGrade < 1) {
        throw Form::GradeTooHighException();
    } else if (_signGrade > 150 || _execGrade > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(Form const& src) : _name(src.getName()), _isSigned(src.getIsSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()){}

Form& Form::operator=(Form const& src) {
    if (this != &src) {
        _isSigned = src.getIsSigned();
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecGrade() const {
    return _execGrade;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
    if (_isSigned) {
        throw Form::FormIsAlreadySigned();
    }
    if (bureaucrat.getGrade() > _signGrade) {
        throw Form::GradeTooLowException();
    }
     _isSigned = true;

}


std::ostream& operator<<(std::ostream& os, const Form& src) {
    os << "Form: " << src.getName() << ", Sign Grade: " << src.getSignGrade() << ", Exec Grade: " << src.getExecGrade() << ", Signed: " << src.getIsSigned() << std::endl;
    return os;
}


const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is Too High";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is Too Low";
}

const char* Form::FormIsAlreadySigned::what() const throw() {
    return "Form is already signed";
}