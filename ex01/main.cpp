#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
    try 
    {
        Bureaucrat bureaucrat("John", 30);
        std::cout << bureaucrat << std::endl;
        Form form("FormA", 40, 30);

        std::cout << form << std::endl;

        // form.beSigned(bureaucrat);
        // std::cout << "Form after being signed: " << form << std::endl;

        bureaucrat.signForm(form);

        Form invalidForm("InvalidForm", 0, 100);
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
