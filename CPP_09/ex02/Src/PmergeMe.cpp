#include "../PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &copy){
	this->operator=(copy);
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy){
	(void)copy;
	return *this;
}

PmergeMe::PmergeMe(int ac, char **av){
	for (int i = 1; i < ac; i++){
		std::string input = av[i];
		if (!IsValideNumber(input))
			throw std::runtime_error("Error\n");
		long num = IsNumberTooLong(input);
		_Vec.push_back(static_cast<int>(num));
		_Dec.push_back(static_cast<int>(num));
	}
}

bool PmergeMe::IsValideNumber(const std::string &str){
	if (str.empty())
		return false;
	
	for (size_t i = 0; i < str.length(); i++){
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

long PmergeMe::IsNumberTooLong(const std::string &str){
	char *end;
	long num = std::strtol(str.c_str(), &end, 10);

	if (*end != '\0' || num < 0 || num > INT_MAX)
		throw std::runtime_error("Error\n");
	
	return num;
}

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
}

int PmergeMe::BinarySearch(const std::vector<int>& vec, int value, int left, int right){
	while(left <= right){
		int mid = left + (right - left) / 2;

		if (vec[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

void PmergeMe::SortVector(){
	if (_Vec.size() <= 1)
		return ;
	std::vector<std::pair<int, int> > pairs;
	int off_elmt = -1;

	for (size_t i = 0; i + 1 < _Vec.size(); i += 2) {
		int a = _Vec[i];
		int b = _Vec[i + 1];
		if (a > b)
			pairs.push_back(std::make_pair(b, a));
		else
			pairs.push_back(std::make_pair(a, b));
	}
	if (_Vec.size() % 2 != 0)
		off_elmt = _Vec[_Vec.size() - 1];
	
	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].second);
	
	std::sort(mainChain.begin(), mainChain.end());
	for(size_t i = 0; i < pairs.size(); i++) {
		int pos = BinarySearch(mainChain, pairs[i].first, 0, mainChain.size() - 1);
		mainChain.insert(mainChain.begin() + pos, pairs[i].first);
	}
	if (off_elmt != -1){
		int pos = BinarySearch(mainChain, off_elmt, 0, mainChain.size() - 1);
		mainChain.insert(mainChain.begin() + pos, off_elmt);
	}
	_Vec = mainChain;
}