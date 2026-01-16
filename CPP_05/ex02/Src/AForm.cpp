#include "../AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
	return "AForm grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "AForm grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

AForm::AForm(): _Name("Insignificant"), _Grade_to_sign(150), _Grade_to_execute(150), _Is_signed(false){
	// std::cout << _Name << " was Created!! -- Grade: " << _Grade << std::endl;
}

AForm::AForm(std::string const &name, int grade_S, int grade_E)
: _Name(name), _Grade_to_sign(grade_S), _Grade_to_execute(grade_E), _Is_signed(false){
	if (_Grade_to_sign < 1 || _Grade_to_execute < 1)
		throw GradeTooHighException();
	else if (_Grade_to_sign > 150 || _Grade_to_execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
: _Name(other._Name), _Grade_to_sign(other._Grade_to_sign), _Grade_to_execute(other._Grade_to_execute), _Is_signed(other._Is_signed){
	*this = other;
}

AForm&	AForm::operator=(const AForm &other){
	if (this != &other){
		_Is_signed = other._Is_signed;
	}
	return *this;
}

AForm::~AForm(){
	std::cout << _Name << " was Deleted!!" << std::endl;
}

int AForm::getGradeToExecute() const{
	return this->_Grade_to_execute;
}

int AForm::getGradeToSign() const{
	return this->_Grade_to_sign;
}

std::string AForm::getName() const{
	return this->_Name;
}

bool AForm::getIsSigned() const{
	return this->_Is_signed;
}

bool AForm::beSigned(Bureaucrat &A){
	if (A.getGrade() > _Grade_to_sign)
		throw GradeTooLowException();
	if (!_Is_signed){
		_Is_signed = true;
		return true;
	}
	return false;
}

void	AForm::execute(Bureaucrat const &executor) const{
	if (!_Is_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _Grade_to_execute)
		throw GradeTooLowException();
	executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& b) {
	os << b.getName() << ", grade to sign: " << b.getGradeToSign() << "." << std::endl;
	os << b.getName() << ", grade to execute: " << b.getGradeToExecute() << ".";
	return os;
}

