#include "../RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("default_Robotomy", 75, 45){
	// std::cout << _Name << " was Created!! -- Grade: " << _Grade << std::endl;

}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
: AForm(target + "_form", 75, 45), _target(target){
	if (_Grade_to_sign < 1 || _Grade_to_execute < 1)
		throw GradeTooHighException();
	else if (_Grade_to_sign > 150 || _Grade_to_execute > 150)
		throw GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other._target, 145, 137){
	*this = other;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this != &other){
		_Is_signed = other._Is_signed;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << _Name << " was Deleted!!" << std::endl;
}

void	RobotomyRequestForm::executeAction() const{
	std::cout << "... Drilling Noises !!!! ..." << std::endl;
	sleep(2);

	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << _target << " failed to robotimize!" << std::endl;

}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& b) {
	os << b.getName() << ", grade to sign: " << b.getGradeToSign() << "." << std::endl;
	os << b.getName() << ", grade to execute: " << b.getGradeToExecute() << ".";
	return os;
}

