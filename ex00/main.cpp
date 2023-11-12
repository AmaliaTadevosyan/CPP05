#include "Bureaucrat.hpp"

int main() {
    try 
    {
        Bureaucrat bureaucrat1("John", 100);
        std::cout << bureaucrat1 << std::endl;

        bureaucrat1.incrementGrade();
        std::cout << "After incrementing grade: " << bureaucrat1.getGrade() << std::endl;

        bureaucrat1.decrementGrade();
        std::cout << "After decrementing grade: " << bureaucrat1.getGrade() << std::endl;


        Bureaucrat bureaucrat2("Alice", 0); // Should throw GradeTooHighException
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}