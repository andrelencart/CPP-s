#include "../RPN.hpp"

int main(int ac, char **av){
	
	if (ac != 2){
		std::cerr << "Error: Needs 2 Arguments" << std::endl;
		return (1);
	}
	RPN rpn;
	std::string result;
	result = rpn.CalculateInput(av[1]);
	if (result.empty())
		return 1;
	std::cout << result << std::endl;
	return 0;
}