#include "../BitcoinExchange.hpp"

// Your program must respect these rules:
// • The program name is btc.
// • Your program must take a file as an argument.
// • Each line in this file must use the following format: "date | value".
// • A valid date will always be in the following format: Year-Month-Day.
// • A valid value must be either a float or a positive integer, between 0 and 1000.

int main(int ac, char **av){
	if (ac == 2){
		if (parsing(av) == 1)
			return 1;
	}
	else if (ac == 1){
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	else{
		std::cout << "The Program Needs TWO Arguments!" << std::endl;
		return 1;
	}
}