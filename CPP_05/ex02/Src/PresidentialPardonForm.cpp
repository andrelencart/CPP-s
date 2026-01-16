#include "../PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("default_Presidential", 25, 5){
	// std::cout << _Name << " was Created!! -- Grade: " << _Grade << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
: AForm(target + "_form", 25, 5), _target(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other._target, 145, 137){
	*this = other;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	(void)other;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << getName() << " was Deleted!!" << std::endl;
}

void	PresidentialPardonForm::executeAction() const{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;

}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& b) {
	os << b.getName() << ", grade to sign: " << b.getGradeToSign() << "." << std::endl;
	os << b.getName() << ", grade to execute: " << b.getGradeToExecute() << ".";
	return os;
}

