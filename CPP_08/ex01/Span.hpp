#pragma once

#include <iostream>

#include <exception>

class Span{
	protected:
		unsigned int _N;
	
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();

		void	addNumber(int num);
		Span	shortestSpan();
		Span	longestSpan();

};

std::ostream& operator<<(std::ostream& os, const Span& f);