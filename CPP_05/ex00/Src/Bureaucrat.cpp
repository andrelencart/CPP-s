#include "../Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low";
}

Bureaucrat::Bureaucrat(): _Name("The_Lowest"), _Grade(150){
	std::cout << _Name << " was Created!! -- Grade: " << _Grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _Name(name), _Grade(grade){
	// if (grade < 1)
	// 	throw GradeTooHighException

	std::cout << _Name << " was Created!! -- Grade: " << _Grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other){
	*this = other;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other){
		_Grade = other._Grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout << _Name << " was Deleted!!" << std::endl;
}

int Bureaucrat::getGrade() const{
	return this->_Grade;
}

std::string Bureaucrat::getName() const{
	return this->_Name;
}

void	Bureaucrat::IncrementGrade(int nb_increments){
	this->_Grade += nb_increments;
}