#include "../Ice.hpp"

Ice::Ice(){
	_type = "ice";
	std::cout << "Ice: " << getType() << " was Created!" << std::endl;
}

Ice::Ice(const Ice& copy){
	*this = copy;
}

Ice& Ice::operator=(const Ice& copy){
	if (this != &copy)
		_type = copy._type;
	return *this;
}

Ice::~Ice(){
	std::cout << "Ice: " << getType() << " was Destroyed!" << std::endl;
}

Ice* Ice::clone()const{
	return new Ice(*this);
}

void	Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}