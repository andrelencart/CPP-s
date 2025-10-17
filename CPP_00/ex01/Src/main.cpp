
#include <iostream>
#include <cstdlib>
#include "../phonebook.hpp"

int	main(int ac, char **av)
{
	(void)av;

	if (ac > 1){
		std::cout << "To Many Arguments" << std::endl;
		return (0);
	}
	PhoneBook PhoneBook;
	std::string cmd;
	std::cout << "Input Command can be (ADD, SEARCH, EXIT)" << std::endl;
	while (std::getline(std::cin, cmd)){	
		if (std::cin.eof())
			exit(0);
		if (cmd == "SEARCH")
			PhoneBook.SearchContact();
		else if (cmd == "ADD")
			PhoneBook.AddContact();
		else if (cmd == "EXIT")
			PhoneBook.Exit();
		else 
			std::cout << "Wrong Command Dumb***" << std::endl;
		std::cout << "Input Command can be (ADD, SEARCH, EXIT)" << std::endl;
	}
	return (0);
}