#include "../Span.hpp"

Span::Span(): _N(1) {
	_numbers.reserve(1);
}

Span::Span(unsigned int N): _N(N) {
	_numbers.reserve(N);
}

Span::Span(const Span &other): _N(other._N), _numbers(other._numbers) {}

Span& Span::operator=(const Span &other){
	if (this != &other){
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int num){
	if (_numbers.size() >= _N)
		throw std::overflow_error("Array FULL !!");
	_numbers.push_back(num);
}

void	Span::addMutipleNumbers(size_t mult){
	if (mult > _N)
		throw std::overflow_error("Too Many NUmbers !!");
	if (_numbers.size() + mult > _N)
		throw std::overflow_error("Array FULL !!");
	for (size_t i = 0; i < mult; i++)
		_numbers.push_back(i);
}

void	Span::addMutipleRandomNumbers(size_t mult){
	if (mult > _N)
		throw std::overflow_error("Too Many Numbers");
	if (_numbers.size() + mult > _N)
		throw std::overflow_error("Array FULL !!");
	for (size_t i = 0; i < mult; i++)
		_numbers.push_back(std::rand() % 10001);
}

int Span::shortestSpan(){
	if (_numbers.size() <= 1)
		throw std::logic_error("Too Few Numbers !!");
	
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for(size_t i = 2; i < sorted.size(); i++){
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan(){
	if (_numbers.size() <= 1)
		throw std::logic_error("Too Few Numbers !!");
	
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	return sorted.back() - sorted.front();
}


