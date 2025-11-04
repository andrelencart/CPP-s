#include "../Brain.hpp"

Brain::Brain(){
	for (int i = 0; i < 100; ++i)
		_ideas[i] = "";
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

void	Brain::setIdea(std::size_t idx, const std::string& idea){
	if (idx < 100)
		_ideas[idx] = idea;
}

std::string Brain::getIdea(std::size_t idx) const{
	if (idx < 100)
		return _ideas[idx];
	return "";
}