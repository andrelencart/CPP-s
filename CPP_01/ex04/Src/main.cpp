
#include "../replace.hpp"

int	main(int ac, char **av){
	
	if (ac != 4){
		std::cout << "Wrong number of Arguments!"  << std::endl;
		std::cout << "Needs a File, a Search string and a Fill string"  << std::endl;
		return 1;
	}

	Replace replacer(av[1], av[2], av[3]);
	replacer.process();

}