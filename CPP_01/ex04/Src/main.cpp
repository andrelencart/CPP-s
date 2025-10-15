#include <iostream>
#include <iomanip>
#include <string>
#include <iterator>
#include <fstream>

int	main(int ac, char **av){
	
	if (ac != 4){
		std::cout << "Wrong number of Arguments!"  << std::endl;
		std::cout << "Needs a File and two different strings"  << std::endl;
		return 1;
	}
	
	std::string in_file = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty()){
		std::cout << "Search Stream cant be EMPTY!!";
		return 1;
	}
	
	std::ofstream out_file;


}