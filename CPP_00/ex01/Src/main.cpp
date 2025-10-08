
#include <iostream>
#include <cstdlib>
#include "../phonebook.hpp"

int	main(void)
{
	PhoneBook PhoneBook;
	std::string cmd;

	while (1){
		std::cout << "Input Command can be (Add, Search, Exit)" << std::endl;
		std::cin >> cmd;
	
		if (std::cin.eof())
			exit(0);
		if (cmd == "Search")
			PhoneBook.SearchContact();
		else if (cmd == "Add")
			PhoneBook.AddContact();
		else if (cmd == "Exit")
			PhoneBook.Exit();
		else 
			std::cout << "Wrong Command Dumb***" << std::endl;
	}
	return (0);
}