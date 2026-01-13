#include "../ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("default_Shrubbery", 145, 137){
	// std::cout << _Name << " was Created!! -- Grade: " << _Grade << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
: AForm(target + "_form", 145, 137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other._target, 145, 137){
	*this = other;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	(void)other;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << getName() << " was Deleted!!" << std::endl;
}

void	ShrubberyCreationForm::executeAction() const{
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not create file");

	file << "       ###\n";
	file << "      #o###\n";
	file << "    #####o###\n";
	file << "   #o#\\#|#/###\n";
	file << "    ###\\|/#o#\n";
	file << "     # }|{  #\n";
	file << "       }|{\n";

	file.close();
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& b) {
	os << b.getName() << ", grade to sign: " << b.getGradeToSign() << "." << std::endl;
	os << b.getName() << ", grade to execute: " << b.getGradeToExecute() << ".";
	return os;
}

