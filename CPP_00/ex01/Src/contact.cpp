#include <iostream>
#include "contacts.hpp"

Contact::Contact(void){
}

Contact::~Contact(void){
	std::cout << "This Conctact has been DELETED!!" << std::endl;
}

// The Functions that will receive the info
void	Contact::SetFstName(const std::string &str){
	this->f_name = str;
}

void	Contact::SetLstName(const std::string &str){
	this->l_name = str;
}

void	Contact::SetNkName(const std::string &str){
	this->nk_name = str;
}

void	Contact::SetPhNumber(const std::string &str){
	this->ph_number = str;
}

void	Contact::SetDkSecret(const std::string &str){
	this->dk_secret = str;
}

// The Functions that will retrieve the info
std::string Contact::GetFstName(){
	return (this->f_name);
}

std::string Contact::GetLstName(){
	return (this->l_name);
}

std::string Contact::GetNkName(){
	return (this->nk_name);
}

std::string Contact::GetPhNumber(){
	return (this->ph_number);
}

std::string Contact::GetDkSecret(){
	return (this->dk_secret);
}