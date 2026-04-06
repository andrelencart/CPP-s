#include "../PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::~PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &copy){
	this->operator=(copy);
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy){
		if (this != &copy){
		_Vec = copy._Vec;
		_Deq = copy._Deq;
		_VecTime = copy._VecTime;
		_DeqTime = copy._DeqTime;
	}
	return *this;
}

PmergeMe::PmergeMe(int ac, char **av){
	for (int i = 1; i < ac; i++){
		std::string input = av[i];
		if (!IsValideNumber(input))
			throw std::runtime_error("Error\n");
		long num = IsNumberTooLong(input);
		_Vec.push_back(static_cast<int>(num));
		_Deq.push_back(static_cast<int>(num));
	}
}

bool PmergeMe::IsValideNumber(const std::string &str){
	if (str.empty())
		return false;
	
	for (size_t i = 0; i < str.length(); i++){
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
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

void PmergeMe::SortPairsByARecursiveVector(std::vector<std::pair<int, int> >& pairs){
	if (pairs.size() <= 1)
		return;

	size_t mid = pairs.size() / 2;
	std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
	std::vector<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());
	SortPairsByARecursiveVector(left);
	SortPairsByARecursiveVector(right);
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;
	while (i < left.size() && j < right.size()){
		if (left[i].second <= right[j].second)
			pairs[k++] = left[i++];
		else
			pairs[k++] = right[j++];
	}
	while (i < left.size())
		pairs[k++] = left[i++];
	while (j < right.size())
		pairs[k++] = right[j++];
}

void PmergeMe::SortPairsByARecursiveDeque(std::deque<std::pair<int, int> >& pairs){
	if (pairs.size() <= 1)
		return;

	size_t mid = pairs.size() / 2;
	std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
	std::deque<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());
	SortPairsByARecursiveDeque(left);
	SortPairsByARecursiveDeque(right);
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;
	while (i < left.size() && j < right.size()){
		if (left[i].second <= right[j].second)
			pairs[k++] = left[i++];
		else
			pairs[k++] = right[j++];
	}
	while (i < left.size())
		pairs[k++] = left[i++];
	while (j < right.size())
		pairs[k++] = right[j++];
}

int PmergeMe::BinarySearchVectorBound(const std::vector<int>& vec, int value, size_t rightBound){
	if (vec.empty())
		return 0;
	if (rightBound >= vec.size())
		rightBound = vec.size() - 1;
	int left = 0;
	int right = static_cast<int>(rightBound);
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (vec[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

int PmergeMe::BinarySearchDequeBound(const std::deque<int>& vec, int value, size_t rightBound){
	if (vec.empty())
		return 0;
	if (rightBound >= vec.size())
		rightBound = vec.size() - 1;
	int left = 0;
	int right = static_cast<int>(rightBound);
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (vec[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

std::vector<size_t> PmergeMe::BuildJacobsthalOrder(size_t pendCount){
	std::vector<size_t> order;
	if (pendCount == 0)
		return order;
	std::vector<bool> used(pendCount, false);
	size_t prev = 1;
	size_t curr = 3;
	while (curr <= pendCount + 1){
		size_t start = curr;
		size_t end = prev + 1;	
		for (size_t idx = start; idx >= end; --idx){
			size_t pendIdx = idx - 2;
			if (pendIdx < pendCount && !used[pendIdx]){
				order.push_back(pendIdx);
				used[pendIdx] = true;
			}
			if (idx == end)
				break;
		}	
		size_t next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	for (size_t i = pendCount; i > 0; --i){
		size_t idx = i - 1;
		if (!used[idx]){
			order.push_back(idx);
			used[idx] = true;
		}
	}
	return order;
}

void PmergeMe::SortVector(){
	struct timeval start, end;
	gettimeofday(&start, NULL);

	if (_Vec.size() <= 1){
		gettimeofday(&end, NULL);
		_VecTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
		return ;
	}
	std::vector<std::pair<int, int> > pairs;
	int off_elmt = -1;

	for (size_t i = 0; i + 1 < _Vec.size(); i += 2) {
		int b = _Vec[i];
		int a = _Vec[i + 1];
		if (b > a)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}
	if (_Vec.size() % 2 != 0)
		off_elmt = _Vec[_Vec.size() - 1];

	SortPairsByARecursiveVector(pairs);
	
	std::vector<int> mainChain;
	std::vector<std::pair<int, int> > pend;

	if (!pairs.empty()){
		mainChain.push_back(pairs[0].first);
		mainChain.push_back(pairs[0].second);
		for (size_t i = 1; i < pairs.size(); ++i){
			mainChain.push_back(pairs[i].second);
			pend.push_back(std::make_pair(pairs[i].first, pairs[i].second));
		}
	}
	if (off_elmt != -1){
		pend.push_back(std::make_pair(off_elmt, INT_MAX));
	}

	std::vector<size_t> order = BuildJacobsthalOrder(pend.size());

	for (size_t oi = 0; oi < order.size(); ++oi){
		size_t p = order[oi];
		int value = pend[p].first;
		int boundValue = pend[p].second;
		size_t bound = mainChain.size() - 1;
		if (boundValue != INT_MAX){
			for (size_t bi = 0; bi < mainChain.size(); ++bi){
				if (mainChain[bi] == boundValue)
				bound = bi;
			}
		}
		int pos = BinarySearchVectorBound(mainChain, value, bound);
		mainChain.insert(mainChain.begin() + pos, value);
	}
	_Vec = mainChain;

	gettimeofday(&end, NULL);
	_VecTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::SortDeque(){
	struct timeval start, end;
	gettimeofday(&start, NULL);

	if (_Deq.size() <= 1){
		gettimeofday(&end, NULL);
		_DeqTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
		return ;
	}
	std::deque<std::pair<int, int> > pairs;
	int off_elmt = -1;

	for (size_t i = 0; i + 1 < _Deq.size(); i += 2) {
		int b = _Deq[i];
		int a = _Deq[i + 1];
		if (b > a)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}
	if (_Deq.size() % 2 != 0)
		off_elmt = _Deq[_Deq.size() - 1];

	SortPairsByARecursiveDeque(pairs);
	
	std::deque<int> mainChain;
	std::deque<std::pair<int, int> > pend;

	if (!pairs.empty()){
		mainChain.push_back(pairs[0].first);
		mainChain.push_back(pairs[0].second);
		for (size_t i = 1; i < pairs.size(); ++i){
			mainChain.push_back(pairs[i].second);
			pend.push_back(std::make_pair(pairs[i].first, pairs[i].second));
		}
	}
	if (off_elmt != -1){
		pend.push_back(std::make_pair(off_elmt, INT_MAX));
	}

	std::vector<size_t> order = BuildJacobsthalOrder(pend.size());

	for (size_t oi = 0; oi < order.size(); ++oi){
		size_t p = order[oi];
		int value = pend[p].first;
		int boundValue = pend[p].second;
		size_t bound = mainChain.size() - 1;
		if (boundValue != INT_MAX){
			for (size_t bi = 0; bi < mainChain.size(); ++bi){
				if (mainChain[bi] == boundValue)
				bound = bi;
			}
		}
		int pos = BinarySearchDequeBound(mainChain, value, bound);
		mainChain.insert(mainChain.begin() + pos, value);
	}
	_Deq = mainChain;

	gettimeofday(&end, NULL);
	_DeqTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::DisplayTime(){
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _Vec.size() 
			<< " elements with std::vector : " << _VecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _Deq.size	() 
			<< " elements with std::deque : " << _DeqTime << " us" << std::endl;
}