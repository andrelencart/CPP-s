#include "../Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade too low";
}

Form::Form(): _Name("Insignificant"), _Grade_to_sign(150), _Grade_to_execute(150), _Is_signed(false){
	// std::cout << _Name << " was Created!! -- Grade: " << _Grade << std::endl;
}

Form::Form(std::string const &name, int grade_S, int grade_E)
: _Name(name), _Grade_to_sign(grade_S), _Grade_to_execute(grade_E), _Is_signed(false){
	if (_Grade_to_sign < 1 || _Grade_to_execute < 1)
		throw GradeTooHighException();
	else if (_Grade_to_sign > 150 || _Grade_to_execute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
: _Name(other._Name), _Grade_to_sign(other._Grade_to_sign), _Grade_to_execute(other._Grade_to_execute), _Is_signed(other._Is_signed){
	*this = other;
}

Form&	Form::operator=(const Form &other){
	if (this != &other){
		_Is_signed = other._Is_signed;
	}
	return *this;
}

Form::~Form(){
	std::cout << _Name << " was Deleted!!" << std::endl;
}

int Form::getGradeToExecute() const{
	return this->_Grade_to_execute;
}

int Form::getGradeToSign() const{
	return this->_Grade_to_sign;
}

std::string Form::getName() const{
	return this->_Name;
}

bool Form::getIsSigned() const{
	return this->_Is_signed;
}

bool Form::beSigned(Bureaucrat &A){
	if (A.getGrade() > _Grade_to_sign)
		throw GradeTooLowException();
	if (!_Is_signed){
		_Is_signed = true;
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Form& b) {
	os << b.getName() << ", grade to sign: " << b.getGradeToSign() << "." << std::endl;
	os << b.getName() << ", grade to execute: " << b.getGradeToExecute() << ".";
	return os;
}

// void	Form::DecrementGrade(int nb_increments){
// 	if (_Grade < 150 && _Grade >= 1)
// 		this->_Grade += nb_increments;
// 	else
// 		throw GradeTooLowException();
// }

// void	Form::IncrementGrade(int nb_increments){
// 	if (_Grade <= 150 && _Grade > 1)
// 		this->_Grade -= nb_increments;
// 	else
// 		throw GradeTooHighException();
// }
