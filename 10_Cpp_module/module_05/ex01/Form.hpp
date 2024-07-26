#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;

    public:
        Form();
        Form(std::string name, int signGrade, int execGrade);
        Form(Form const& src);
        ~Form();
        Form& operator=(Form const& src);

        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class FormIsAlreadySigned : public std::exception {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& os, const Form& src);

#endif