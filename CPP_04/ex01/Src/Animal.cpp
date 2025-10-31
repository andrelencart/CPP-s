#include "../Animal.hpp"

Animal::Animal(): _type("Mammal"){
	std::cout << "A Animal was Created!" << std::endl;
}

Animal::Animal(std::string type){
	_type = type;
	std::cout << "Animal: " << _type << " was Created!" << std::endl;
}

Animal::Animal(const Animal& other){
	*this = other;
}

Animal& Animal::operator=(const Animal& other){
	if (this != &other){
		_type = other._type;
	}
	return *this;
}

Animal::~Animal(){
	std::cout << "A Animal was Destroyed!" << std::endl;
}

void	Animal::makeSound()const{
	std::cout << "FAAAAAAAAAAAAAAAAAAAAHHHHHHHHHH" << std::endl;
}

std::string Animal::getType()const{
	return _type;
}