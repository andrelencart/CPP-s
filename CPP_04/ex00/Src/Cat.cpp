#include "../Cat.hpp"

Cat::Cat(): Animal("Cat"){
	std::cout << "A " << _type << " was Created!" << std::endl;
}

Cat::Cat(const Cat& other){
	*this = other;
}

Cat& Cat::operator=(const Cat& other){
	if (this != &other){
		_type = other._type;
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "A Cat was Destroyed!" << std::endl;
}

void	Cat::makeSound() const{
	std::cout << "MIAU!! MIAU!! M***** FU****!!" << std::endl;
}

// std::string Cat::getType(){
// 	return _type;
// }