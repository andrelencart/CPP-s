#include "../Bureaucrat.hpp"
#include "../AForm.hpp"
#include "../Intern.hpp"

int main(void) {
	std::cout << "=== Testing Intern makeForm ===" << std::endl;

	Intern someRandomIntern;
	AForm* form1;
	AForm* form2;
	AForm* form3;
	AForm* form4;

	std::cout << "\n--- Creating valid forms ---" << std::endl;
	form1 = someRandomIntern.makeForm("shrubbery creation", "home");
	form2 = someRandomIntern.makeForm("robotomy request", "Bender");
	form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

	std::cout << "\n--- Creating invalid form ---" << std::endl;
	form4 = someRandomIntern.makeForm("unknown form", "target");

	// std::cout << "\n--- Testing created form1 ---" << std::endl;
	// if (form1) {
	// 	Bureaucrat bob("Bob", 1);
	// 	std::cout << *form1 << std::endl;
	// 	bob.SignForm(*form1);
	// 	bob.executeForm(*form1);
	// }

	// std::cout << "\n--- Testing created form2 ---" << std::endl;
	// if (form2) {
	// 	Bureaucrat alice("Alice", 1);
	// 	std::cout << *form2 << std::endl;
	// 	alice.SignForm(*form2);
	// 	alice.executeForm(*form2);
	// }

	// std::cout << "\n--- Testing created form3 ---" << std::endl;
	// if (form3) {
	// 	Bureaucrat president("President", 1);
	// 	std::cout << *form3 << std::endl;
	// 	president.SignForm(*form3);
	// 	president.executeForm(*form3);
	// }

	std::cout << "\n--- Cleaning up ---" << std::endl;
	delete form1;
	delete form2;
	delete form3;
	delete form4;
}