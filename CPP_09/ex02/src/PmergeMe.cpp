#include "../PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &copy){
	this->operator=(copy);
};

PmergeMe &PmergeMe::operator=(const PmergeMe &copy){
	(void)copy;
	return *this;
};

PmergeMe::PmergeMe(int ac, char **av){
	for (int i = 1; i < ac; i++){
		
	}

};


