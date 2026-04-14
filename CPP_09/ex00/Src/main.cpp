#include "../BitcoinExchange.hpp"

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