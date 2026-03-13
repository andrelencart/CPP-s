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
		// sp.addMutipleNumbers(5);
		std::cout << std::endl;
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---Test 10000 Numbers---" << std::endl;
	try {
		Span spa = Span(10);
		spa.addMutipleNumbers(10);
		std::cout << std::endl;
		spa.printNumbers();
		std::cout << std::endl;
		std::cout << "Shortest: " << spa.shortestSpan() << std::endl;
		std::cout << "Longest: " << spa.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	// std::cout << std::endl;

	std::cout << "---Test Random Numbers---" << std::endl;
	std::cout << std::endl;
	Span span = Span(100);
	try {
		span.addMutipleRandomNumbers(100);
		span.printNumbers();
		std::cout << std::endl;
		std::cout << "Shortest: " << span.shortestSpan() << std::endl;
		std::cout << "Longest: " << span.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	// std::cout << std::endl;
	
	return 0;
}
