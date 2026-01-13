#include "../RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("default_Robotomy", 75, 45){
	// std::cout << _Name << " was Created!! -- Grade: " << _Grade << std::endl;
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
: AForm(target + "_form", 72, 45), _target(target){
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other._target, 145, 137){
	*this = other;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	(void)other;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << getName() << " was Deleted!!" << std::endl;
}

void	RobotomyRequestForm::executeAction() const{
	std::cout << "... Drilling Noises !!!! ..." << std::endl;
	sleep(2);

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

