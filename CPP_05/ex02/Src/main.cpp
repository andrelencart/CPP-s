#include "../Bureaucrat.hpp"
#include "../AForm.hpp"
#include "../ShrubberyCreationForm.hpp"
#include "../RobotomyRequestForm.hpp"
#include "../PresidentialPardonForm.hpp"

int main(void) {
	std::cout << "=== Testing ShrubberyCreationForm ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 140);
		ShrubberyCreationForm shrub("home");
	
		std::cout << bob << std::endl;
		std::cout << shrub << std::endl;
	
		bob.SignForm(shrub);
		bob.executeForm(shrub);
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 45);
		RobotomyRequestForm robot("Bender");
	
		std::cout << alice << std::endl;
		std::cout << robot << std::endl;
	
		alice.SignForm(robot);
		alice.executeForm(robot);
		alice.executeForm(robot);
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
	
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
	
		president.SignForm(pardon);
		president.executeForm(pardon);
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Failures ===" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		ShrubberyCreationForm shrub2("garden");
	
		std::cout << intern << std::endl;
		intern.SignForm(shrub2);
		intern.executeForm(shrub2);
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}	
	return 0;
}