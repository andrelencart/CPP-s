
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
	std::string value;

	if (this->contact_index == 8)
		this->contact_index = 0;

	std::cout << "First Name:";
	std::cin >> value;
	this->contact[this->contact_index].SetFstName(value);
	std::cout << "Last Name:";
	std::cin >> value;
	this->contact[this->contact_index].SetLstName(value);
	std::cout << "Nick Name:";
	std::cin >> value;
	this->contact[this->contact_index].SetNkName(value);
	std::cout << "Phone Number:";
	std::cin >> value;
	this->contact[this->contact_index].SetPhNumber(value);
	std::cout << "Darkest Sectret:";
	std::cin >> value;
	this->contact[this->contact_index].SetDkSecret(value);
	this->contact_index++;
	if (this->max_index != 8)
		this->max_index++;
}

void	PhoneBook::PrintContactInfo(int i){
	std::cout << "First Name:" << this->contact[i].GetFstName() << std::endl;
	std::cout << "Last Name:" << this->contact[i].GetLstName() << std::endl;
	std::cout << "Nick Name:" << this->contact[i].GetNkName() << std::endl;
	std::cout << "Phone Number:" << this->contact[i].GetPhNumber() << std::endl;
	std::cout << "Darkest Secret:" << this->contact[i].GetDkSecret() << std::endl;
}

void	PrintColum(std::string text, int width){

	if ((int)text.size() > width)
		std::cout << std::setw(width) << text.substr(0, width - 1) + "." << "|";
	else
		std::cout << std::setw(width) << text << "|";
}

void	PrintUnderline(const std::vector<int> widths){
	// std::cout << "|";
	for (size_t j = 0; j < widths.size(); ++j){
		int	w = widths[j];
		for (int i = 0; i < w; ++i){
			std::cout << "-";
		}
		std::cout << "|";
	}
	std::cout << std::endl;
}

void	PhoneBook::SearchContact(void){
	std::string input;
	std::vector<int> widths (4, 10);
	
	std::cout << "|";
	PrintColum("Index", 10);
	PrintColum("First Name", 10);
	PrintColum("Last Name", 10);
	PrintColum("Nick Name", 10);
	std::cout << std::endl;
	
	std::cout << "|";
	PrintUnderline(widths);
	for (int i = 0; i < this->max_index; ++i){
		std::stringstream ss;
		ss << i;
		std::cout << "|";
		PrintColum(ss.str(), 10);
		PrintColum(this->contact[i].GetFstName(), 10);
		PrintColum(this->contact[i].GetLstName(), 10);
		PrintColum(this->contact[i].GetNkName(), 10);
		std::cout << std::endl;
	}
	
	std::cout << "Insert Contact Index" << std::endl;
	std::cin >> input;
	if (input.size() != 1 || !isdigit(input[0])){
		std::cout << "Invalid Index!" << std::endl;
		return ;
	}
	int	idx = input[0] - '0';
	if (idx < 0 || idx >= max_index){
		std::cout << "Invalid Index!" << std::endl;
		return ;
	}
	PrintContactInfo(idx);
}


void	PhoneBook::Exit(void){
	exit(0);
}