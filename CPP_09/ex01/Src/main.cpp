#include "../RPN.hpp"

int main(int ac, char **av){
	
	RPN rpn;
	if (ac != 2){
		std::cerr << "Error: Needs 2 Arguments" << std::endl;
		exit(1);
	}
	std::string result;
	result = rpn.CalculateInput(av[1]);
	std::cout << result << std::endl;
}