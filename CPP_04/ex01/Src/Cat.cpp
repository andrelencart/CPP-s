#include "../Cat.hpp"

Cat::Cat(): Animal("Cat"), _ideas(new Brain()){
	for (int i = 0; i < 100; i++)
		_ideas->setIdea(i, "I dont Have Ideas im a CAT");
	std::cout << "A Cat was Created!" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other), _ideas(other._ideas){
	
}

Cat& Cat::operator=(const Cat& other){
	if (this != &other){
		Animal::operator=(other);
		_ideas = other._ideas;
	}
	return *this;
}

Cat::~Cat(){
	delete _ideas;
	std::cout << "A Cat was Destroyed!" << std::endl;
}

void	Cat::makeSound() const{
	std::cout << "MIAU!! MIAU!! M***** FU****!!" << std::endl;
}

std::string Cat::getIdea(std::size_t idx) const{
	return _ideas->getIdea(idx);
}


