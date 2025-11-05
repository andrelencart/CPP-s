#include "../Cure.hpp"

Cure::Cure(){
	_type = "cure";
	std::cout << "Cure: " << getType() << " was Created!" << std::endl;
}

Cure::Cure(const Cure& copy){
	*this = copy;
}

Cure& Cure::operator=(const Cure& copy){
	if (this != &copy)
		_type = copy._type;
	return *this;
}

Cure::~Cure(){
	std::cout << "Cure: " << getType() << " was Destroyed!" << std::endl;
}

Cure* Cure::clone()const{
	return new Cure(*this);
}

void	Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}