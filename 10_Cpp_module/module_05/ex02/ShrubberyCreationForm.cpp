#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade()){
    this->_target = src._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src) {
    if (this != &src) {
        this->_target = src._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned() || executor.getGrade() > getExecGrade()) {
        throw AForm::GradeTooLowException();
    }

    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open()) {
        throw ShrubberyCreationForm::failToOpenFile();
    }
    
    file << "    *" << std::endl;
    file << "   /.\\ " << std::endl;
    file << "  /o..\\" << std::endl;
    file << "  /..o\\" << std::endl;
    file << " /.o..o\\" << std::endl;
    file << " /...o.\\" << std::endl;
    file << "/..o....\\" << std::endl;
    file << "^^^[_]^^^" << std::endl;

    file.close();
    std::cout << "Shrubbery has been created successfully." << std::endl;
}