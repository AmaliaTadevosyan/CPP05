#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    ShrubberyCreationForm	SH("s1");
    RobotomyRequestForm R("r");
    PresidentialPardonForm P("p");
    Bureaucrat b("LOL", 125);
    try
    {
        R.beSigned(b);
        b.signForm(R);
        R.execute(b);
        b.executeForm(R);
        std::cout << R << std::endl;

        std::cout << SH << std::endl;
        b.signForm(SH);
        SH.beSigned(b);
        SH.execute(b);
        b.executeForm(SH);

        std::cout << P << std::endl;
        P.beSigned(b);
        b.signForm(P);
        P.execute(b);
        b.executeForm(P);
        std::cout << P << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}