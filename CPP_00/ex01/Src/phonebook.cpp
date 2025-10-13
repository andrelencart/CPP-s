
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


void	ParseInput(std::string &input, std::string ColumName){

	while (true){
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		if (input.empty()){
			std::cout << ColumName;
			continue;
		}
		if (input.find('\t') != std::string::npos || input.find(' ') != std::string::npos){
			std::cout << "Please no Tabs or Spaces" << std::endl;
			std::cout << ColumName;
			continue ;
		}
		if (ColumName == "Phone Number:"){
			bool isNumeric = true;
			for (size_t i = 0; i < input.length(); ++i) {
				if (!isdigit(input[i])) {
					isNumeric = false;
					break;
				}
			}
			if (!isNumeric) {
				std::cout << "Number!!" << std::endl;
				std::cout << ColumName;
				continue;
			}
		}
		break ;
	}
}

void	PhoneBook::AddContact(void){
	std::string input;

	if (this->contact_index == 8)
		this->contact_index = 0;

	std::cout << "First Name: ";
	ParseInput(input, "First Name:");
	this->contact[this->contact_index].SetFstName(input);
	std::cout << "Last Name: ";
	ParseInput(input, "Last Name:");
	this->contact[this->contact_index].SetLstName(input);
	std::cout << "Nick Name: ";
	ParseInput(input, "Nick Name:");
	this->contact[this->contact_index].SetNkName(input);
	std::cout << "Phone Number: ";
	ParseInput(input, "Phone Number:");
	this->contact[this->contact_index].SetPhNumber(input);
	std::cout << "Darkest Secret: ";
	ParseInput(input, "Darkest Secret:");
	this->contact[this->contact_index].SetDkSecret(input);
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

// void	PrintUnderline(const std::vector<int> widths){
// 	// std::cout << "|";
// 	for (size_t j = 0; j < widths.size(); ++j){
// 		int	w = widths[j];
// 		for (int i = 0; i < w; ++i){
// 			std::cout << "-";
// 		}
// 		std::cout << "|";
// 	}
// 	std::cout << std::endl;
// }

void	PhoneBook::SearchContact(void){
	std::string input;
	// std::vector<int> widths (4, 10);
	
	std::cout << "|";
	PrintColum("Index", 10);
	PrintColum("First Name", 10);
	PrintColum("Last Name", 10);
	PrintColum("Nick Name", 10);
	std::cout << std::endl;
	
	// std::cout << "|";
	// PrintUnderline(widths);
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
	std::getline(std::cin, input);
	if (input.size() != 1 || !isdigit(input[0])){
		std::cout << "Invalid Index!" << std::endl;
		return ;
	}
	int	idx = input[0] - '0';
	if (idx < 0 || idx >= max_index){
		std::cout << "IT CAN ONLY BE THE INDEXS PRESENT AT THE TABLE ABOVE!" << std::endl;
		return ;
	}
	PrintContactInfo(idx);
}


void	PhoneBook::Exit(void){
	exit(0);
}
	