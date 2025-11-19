#include "../PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("default_Robotomy", 25, 5){
	// std::cout << _Name << " was Created!! -- Grade: " << _Grade << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
: AForm(target + "_form", 75, 45), _target(target){
	if (_Grade_to_sign < 1 || _Grade_to_execute < 1)
		throw GradeTooHighException();
	else if (_Grade_to_sign > 150 || _Grade_to_execute > 150)
		throw GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other._target, 145, 137){
	*this = other;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this != &other){
		_Is_signed = other._Is_signed;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << _Name << " was Deleted!!" << std::endl;
}

void	PresidentialPardonForm::executeAction() const{
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox." << std::endl;

}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& b) {
	os << b.getName() << ", grade to sign: " << b.getGradeToSign() << "." << std::endl;
	os << b.getName() << ", grade to execute: " << b.getGradeToExecute() << ".";
	return os;
}

