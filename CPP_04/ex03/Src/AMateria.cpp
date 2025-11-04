#include "../AMateria.hpp"


AMateria::AMateria(): _type("Default"){
	std::cout << "AMateria: " << _type << " was Created!" << std::endl;
}

AMateria::AMateria(std::string const& type): _type(type){
	std::cout << "AMateria: " << _type << " was Created!" << std::endl;
}

AMateria::AMateria(const AMateria& copy){
	*this = copy;
}

AMateria& AMateria::operator=(const AMateria& copy){
	if (this != &copy)
		_type = copy._type;
	return *this;
}

AMateria::~AMateria(){
	std::cout << "AMateria: " << _type << " was Destroyed!" << std::endl;
}

std::string const& AMateria::getType()const{
	return _type;
}

AMateria* AMateria::clone()const{

}

void	AMateria::use(ICharacter& target){
	
}