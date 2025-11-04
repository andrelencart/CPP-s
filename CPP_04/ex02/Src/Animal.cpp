#include "../Animal.hpp"

AAnimal::AAnimal(): _type("Mammal"){
	std::cout << "A AAnimal was Created!" << std::endl;
}

AAnimal::AAnimal(std::string type){
	_type = type;
	std::cout << "AAnimal: " << _type << " was Created!" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other){
	*this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other){
	if (this != &other){
		_type = other._type;
	}
	return *this;
}

AAnimal::~AAnimal(){
	std::cout << "A AAnimal was Destroyed!" << std::endl;
}

void	AAnimal::makeSound()const{
	std::cout << "FAAAAAAAAAAAAAAAAAAAAHHHHHHHHHH" << std::endl;
}

std::string AAnimal::getType()const{
	return _type;
}

std::string AAnimal::getIdea(std::size_t idx) const{
	(void)idx;
	return std::string();
}