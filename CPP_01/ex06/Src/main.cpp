#include "../Harl.hpp"

int	main(int ac, char **av){
	Harl harl;

	if (ac <= 1){
		std::cout << "Harl has nothing to Complain About?" << std::endl;
		std::cout << "He must be Really Sick Today!!" << std::endl;

	}
	else
		harl.complain(av[1]);

}