#include "../Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low";
}

Bureaucrat::Bureaucrat(): _Name("The_Lowest"), _Grade(150){
	// std::cout << _Name << " was Created!! -- Grade: " << _Grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _Name(name), _Grade(grade){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
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

void	Bureaucrat::DecrementGrade(unsigned int nb_increments){
	if (_Grade < 150 && _Grade >= 1 && _Grade + nb_increments <= 150)
		this->_Grade += nb_increments;
	else
		throw GradeTooLowException();
}

void	Bureaucrat::IncrementGrade(unsigned int nb_increments){
	if (_Grade <= 150 && _Grade > 1 && _Grade - nb_increments >= 1)
		this->_Grade -= nb_increments;
	else
		throw GradeTooHighException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}