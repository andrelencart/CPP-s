#include "../Dog.hpp"

Dog::Dog(): Animal("Dog"), _ideas(new Brain()){
	for (int i = 0; i < 100; i++)
		_ideas->setIdea(i, "I dont Have Ideas im a DOG");
	std::cout << "A Dog was Created!" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other), _ideas(other._ideas){
}

Dog& Dog::operator=(const Dog& other){
	if (this != &other){
		Animal::operator=(other);
		_ideas = other._ideas;
	}
	return *this;
}

Dog::~Dog(){
	delete _ideas;
	std::cout << "A Dog was Destroyed!" << std::endl;
}

void	Dog::makeSound()const{
	std::cout << "BARK!! BARK!! M***** FU****!!" << std::endl;
}

std::string Dog::getIdea(std::size_t idx) const{
	return _ideas->getIdea(idx);
}