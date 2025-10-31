#include "../Brain.hpp"

Brain::Brain(){
	std::cout << "A Brain was Created!" << std::endl;
}

Brain::Brain(const Brain& other){
	for (int i = 0; i < 100; ++i)
		_ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other){
	if (this != &other){
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain(){
	std::cout << "A Brain was Destroyed!" << std::endl;
}
