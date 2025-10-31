#include "../Cat.hpp"

Cat::Cat(): Animal("Cat"){
	for (int i = 0; i < 100; i++)
		_ideas[i] = "I dont Have Ideas im a CAT!!";
	std::cout << "A Cat was Created!" << std::endl;
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
	delete[] _ideas;
	std::cout << "A Cat was Destroyed!" << std::endl;
}

void	Cat::makeSound() const{
	std::cout << "MIAU!! MIAU!! M***** FU****!!" << std::endl;
}

