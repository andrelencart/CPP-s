
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "../phonebook.hpp"

PhoneBook::PhoneBook(void){
	contact_index = 0;
	max_index = 0;

	std::cout << "Ready to Register Contact!" << std::endl;
}

PhoneBook::~PhoneBook(void){
	std::cout << "PhoneBook Deleted!" << std::endl;
}


void	PhoneBook::AddContact(void){
	
}