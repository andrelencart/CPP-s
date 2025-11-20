#include "../Intern.hpp"

Intern::Intern(){
	std::cout << "Intern Created!" << std::endl;
}

Intern::Intern(const Intern &other){
	*this = other;
}

Intern& Intern::operator=(const Intern &other){
	(void) other;
	return *this;
}

Intern::~Intern(){
	std::cout << "Intern Destroyed!" << std::endl;
}

AForm	*Intern::makeForm(std::string FormName, std::string FormTarget){
	std::string FormType[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};

	int	FormIndex = -1;
	for (int i = 0; i < 3; ++i){
		if (FormType[i] == FormName){
			FormIndex = i;
			break;
		}
	}

	switch (FormIndex){
		case 0:
			std::cout << "An Intern creates a ShrubberyCreation Form!" << std::endl;
			return new ShrubberyCreationForm(FormTarget);
			break;
		case 1:
			std::cout << "An Intern creates a RobotomyRequest Form!" << std::endl;
			return new RobotomyRequestForm(FormTarget);
			break;
		case 2:
			std::cout << "An Intern creates a PresidentioalPardon Form!" << std::endl;
			return new PresidentialPardonForm(FormTarget);
			break;
		default:
			std::cout << "Error: Form Name: " << FormName << " does not exist!"<< std::endl;
			return NULL;
			break;
	}
}