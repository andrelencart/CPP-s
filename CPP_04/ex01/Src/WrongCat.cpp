#include "../WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat"){
	std::cout << "A WrongCat was Created!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other){
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
	if (this != &other){
		_type = other._type;
	}
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "A WrongCat was Destroyed!" << std::endl;
}

void	WrongCat::makeSound() const{
	std::cout << "MIAU!! MIAU!! I'M THE WRONG ONE!!" << std::endl;
}

