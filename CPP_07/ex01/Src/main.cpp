#include "../iter.hpp"

void printInt(int const& n) {
	std::cout << n << " ";
}

void incrementInt(int& n) {
	n += 5;
}

void printString(std::string const& s) {
	std::cout << s << " ";
}

int main(void) {
	int arr[] = {1, 2, 3, 4, 5};
	
	std::string sarr[] = {"hello", "world", "test"};

	std::cout << "Original array: ";
	::iter(arr, 5, printInt);
	std::cout << std::endl;

	::iter(arr, 5, incrementInt);
	std::cout << "After increment: ";
	::iter(arr, 5, printInt);
	std::cout << std::endl;

	std::cout << "String array: ";
	::iter(sarr, 3, printString);
	std::cout << std::endl;

	return 0;
}