#include "../Dog.hpp"

Dog::Dog(): Animal("Dog"){
	std::cout << "A Dog was Created!" << std::endl;
}

Dog::Dog(const Dog& other){
	*this = other;
}

Dog& Dog::operator=(const Dog& other){
	if (this != &other){
		_type = other._type;
	}
	return *this;
}

Dog::~Dog(){
	delete[] _ideas;
	std::cout << "A Dog was Destroyed!" << std::endl;
}

void	Dog::makeSound()const{
	std::cout << "BARK!! BARK!! M***** FU****!!" << std::endl;
}

// std::string Dog::getType(){
// 	return _type;
// }