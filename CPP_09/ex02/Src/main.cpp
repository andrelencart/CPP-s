#include "../PmergeMe.hpp"

int main(int ac, char **av){

	if (ac < 2){
		std::cerr << "Error: It needs 2 Arguments" << std::endl;
		return 1;
	}
	try{
		PmergeMe Pm(ac, av);
		Pm.DisplayOutput("Before");
		Pm.SortVector();
		Pm.SortDeque();
		std::cout << std::endl;
		Pm.DisplayOutput("After");
		std::cout << std::endl;
		Pm.DisplayTime();
	}
	catch (const std::exception &e){
		std::cerr << e.what();
		return 1;
	}
	return 0;
}