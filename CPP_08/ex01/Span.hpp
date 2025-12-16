#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <limits.h>

class Span{
	private:
		unsigned int _N;
		std::vector<int> _numbers;
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();

		void	addNumber(int num);
		int	shortestSpan();
		int	longestSpan();
		void addMutipleNumbers(size_t mult);
		void addMutipleRandomNumbers(size_t mult);
};

std::ostream& operator<<(std::ostream& os, const Span& f);