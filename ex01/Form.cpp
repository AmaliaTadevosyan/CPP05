#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeRequiredToSign(0), _gradeRequiredToExecute(0)
{
    std::cout << "Form default constructor called!" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeToSign), _gradeRequiredToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::~Form()
{
    std::cout << "Form destructor called!" << std::endl;
}

Form::Form(const Form &other) : _name(other._name),  _isSigned(other._isSigned)
, _gradeRequiredToSign(other._gradeRequiredToSign), _gradeRequiredToExecute(other._gradeRequiredToExecute)
{
    std::cout << "Copy Constructor is called" << std::endl;
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        // Do nothing
    }
    return (*this);
}

const std::string& Form::getName() const
{
    return this->_name;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

int Form::getGradeRequiredToSign() const
{
    return this->_gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const
{
    return this->_gradeRequiredToExecute;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeRequiredToSign)
    {
        this->_isSigned = true;
    }
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low.";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade required to sign: " << form.getGradeRequiredToSign()
       << ", Grade required to execute: " << form.getGradeRequiredToExecute();
    return os;
}
