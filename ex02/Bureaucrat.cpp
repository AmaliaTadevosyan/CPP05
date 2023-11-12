#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default")
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
    _grade = 0;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighExeption();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowExeption();
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureacrat destructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
    std::cout << "Bureaucrat copy constructor called." << std::endl;
    this-> _grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Buraucrat assignmant operator called." << std::endl;
    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::setGrade(int grade) {
    this->_grade = grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade > 1)
        _grade--;
    else
        throw GradeTooHighExeption();
}

void Bureaucrat::decrementGrade()
{
    if (_grade < 150)
        _grade++;
    else
        throw GradeTooLowExeption();
}

const char* Bureaucrat::GradeTooHighExeption::what() const throw()
{
    return "Grade is too high.";
}

const char* Bureaucrat::GradeTooLowExeption::what() const throw()
{
    return "Grade is too low.";
}

void    Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << "Bureacrat " << this->_name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e){
        std::cout << "Bureacrat " << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(Form const &form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << this->getName() << " couldn't execute " << form.getName() << "because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream &outputStream, const Bureaucrat &ref)
{
    outputStream << ref.getName() << ", bureaucrat grade " << ref.getGrade();
    return (outputStream);
}