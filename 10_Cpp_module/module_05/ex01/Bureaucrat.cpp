#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : _name(_name) {
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
    this->_grade = _grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) {
    *this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& src) {
    if (this != &src) {
        this->_grade = src.getGrade();
    }
    return *this;
}


void Bureaucrat::incrementGrade() {
    if (this->_grade == 1)
        throw GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade == 150)
        throw GradeTooLowException();
    this->_grade++;
}


std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::signForm(Form form) {
    try {
        form.getIsSigned();
        std::cout << this->_name << " signed " << form.getName() << std::endl;

    } catch (Form::GradeTooLowException &e) {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src) {
    os << src.getName() << " has grade " << src.getGrade() << std::endl;
    return os;
}