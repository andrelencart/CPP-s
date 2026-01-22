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
		std::string input = av[i];
		if (!IsValideNumber(input))
			throw std::runtime_error("Error\n");
		long num = IsNumberTooLong(input);
		_Vec.push_back(static_cast<int>(num));
		_Dec.push_back(static_cast<int>(num));
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

long PmergeMe::IsNumberTooLong(const std::string &str){
	char *end;
	long num = std::strtol(str.c_str(), &end, 10);

	if (*end != '\0' || num < 0 || num > INT_MAX)
		throw std::runtime_error("Error\n");
	
	return num;
};

void PmergeMe::DisplayOutput(std::string str){
	if (str == "Before")
		std::cout << "Before: ";
	if (str == "After")
		std::cout << "After: ";
	for (size_t i = 0; i < _Vec.size(); i++){
		std::cout << _Vec[i];
		if (i < _Vec.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
};

