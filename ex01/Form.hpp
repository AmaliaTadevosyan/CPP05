#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeRequiredToSign;
        const int _gradeRequiredToExecute;
    public:
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form& operator=(const Form &other);
        virtual ~Form();

        void beSigned(Bureaucrat &bureaucrat);
        const std::string& getName() const;
        bool    getIsSigned() const;
        int     getGradeRequiredToSign() const;
        int     getGradeRequiredToExecute() const;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif