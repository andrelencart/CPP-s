#include "../Span.hpp"
#include <cstdlib>
#include <ctime>



int main(){
	std::srand(std::time(0));

	std::cout << "---Subject Test---" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---Test 10000 Numbers---" << std::endl;
	try {
		Span spa = Span(10);
		spa.addMutipleNumbers(10);
		std::cout << spa.shortestSpan() << std::endl;
		std::cout << spa.longestSpan() << std::endl;
		std::cout << std::endl;
		spa.printNumbers();
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---Test Random Numbers---" << std::endl;
	Span span = Span(100);
	try {
		span.addMutipleRandomNumbers(100);
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
		std::cout << std::endl;
		span.printNumbers();
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	return 0;
}
