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

bool PmergeMe::IsValideNumber(const std::string &str){
	if (str.empty())
		return false;
	
	for (size_t i = 0; i < str.length(); i++){
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
};

