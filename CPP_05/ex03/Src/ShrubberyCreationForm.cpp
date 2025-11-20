#include "../ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("default_Shrubbery", 145, 137){
	// std::cout << _Name << " was Created!! -- Grade: " << _Grade << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
: AForm(target + "_form", 145, 137), _target(target){
	if (_Grade_to_sign < 1 || _Grade_to_execute < 1)
		throw GradeTooHighException();
	else if (_Grade_to_sign > 150 || _Grade_to_execute > 150)
		throw GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other._target, 145, 137){
	*this = other;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	if (this != &other){
		_Is_signed = other._Is_signed;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << _Name << " was Deleted!!" << std::endl;
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

