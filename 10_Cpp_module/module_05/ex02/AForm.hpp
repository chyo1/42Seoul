#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;

    public:
        AForm();
        AForm(std::string name, int signGrade, int execGrade);
        AForm(AForm const& src);
        virtual ~AForm();
        AForm& operator=(AForm const& src);

        std::string getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(Bureaucrat& bureaucrat);

        virtual void execute(Bureaucrat const& executor) const = 0;

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

std::ostream& operator<<(std::ostream& os, const AForm& src);

#endif