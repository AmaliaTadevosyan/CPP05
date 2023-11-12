#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery", 145, 137)
{
    std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("Shrubber", 145, 137)
{
    std::cout << "ShrubberyCreationForm parameter constructor" << std::endl;
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form("Shrubbery", 145, 137)
{
    std::cout << "ShrubberCreationForm copy constructor" << std::endl;
    _target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    std::cout << "ShrubberyCreationForm copy Assignment operator" << std::endl;
    if (this != &other)
    {
        Form::operator=(other);
        _target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw FormNotSigned();
    if (executor.getGrade() > this->getGradeRequiredToExecute())
        throw GradeTooLowException();
    std::fstream outfile(_target + "_Shrubbery", std::fstream::out);
    std::cout << "HELLO" << std::endl;
    if (outfile.is_open())
    {
       outfile << "          42          " << std::endl;
       outfile << "         42 42        " << std::endl;
       outfile << "      42 42 42 42     " << std::endl;
       outfile << "   42 42 42 42 42 42  " << std::endl;
       outfile << "          42          " << std::endl;
       outfile.close();
    }
    else    
        std::cout << "Error" << std::endl;
}