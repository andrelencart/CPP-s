#include "../Harl.hpp"

Harl::Harl(){

}

Harl::~Harl(){

}

void	Harl::debug(){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int	harlcases(std::string cases[4], std::string level){
	if (level == (cases[0]))
		return 1;
	if (level == cases[1])
		return 2;
	if (level == (cases[2]))
		return 3;
	if (level == (cases[3]))
		return 4;
	else
		return 5;
}

void	Harl::complain(std::string level){
	int	cases;
	std::string comments[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	cases = harlcases(comments, level);

	switch(cases){
		case 1:
			std::cout << "[Debug]" << std::endl;
			this->debug();
			std::cout << std::endl;
		case 2:
			std::cout << "[Info]" << std::endl;
			this->info();
			std::cout << std::endl;
		case 3:
			std::cout << "[Warning]" << std::endl;
			this->warning();
			std::cout << std::endl;
		case 4:
			std::cout << "[Error]" << std::endl;
			this->error();
			std::cout << std::endl;
			break ;
		case 5:
			std::cout << "[Away]" << std::endl;
			std::cout << "Harl is on the Phone." << std::endl;
			std::cout << "He cant complain Right Now!!" << std::endl;
			std::cout << std::endl;
			break ;
	}
	return ;
}