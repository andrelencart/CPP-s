#include "../WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Mammal"){
	std::cout << "A WrongAnimal was Created!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type){
	_type = type;
	std::cout << "WrongAnimal: " << _type << " was Created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
	if (this != &other){
		_type = other._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "A WrongAnimal was Destroyed!" << std::endl;
}

void	WrongAnimal::makeSound()const{
	std::cout << "FAAAAAAAAAAAAAAAAAAAAHHHHHHHHHH I'M THE WRONG ONE!!!" << std::endl;
}

std::string WrongAnimal::getType()const{
	return _type;
}