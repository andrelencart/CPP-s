#include "../BitcoinExchange.hpp"

// 2011-01-03 | 3

bool isValidDate(const std::string& date){
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++){
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || day < 1 || month > 12)
		return false;
	switch (month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day > 31)
				return false;
			break;
		case 4: case 6: case 9: case 11:
			if (day > 30)
				return false;
			break;
		case 2:
			bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
			if (day > (isLeap ? 29 : 28))
				return false;
			break;
	}
	return true;
}

bool isValidValue(const float &value){
	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000){
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}	

bool parsingline(const std::string &line, std::string &date, float &value){
	size_t pipePos = line.find('|');
	if (pipePos == std::string::npos){
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}
	date = line.substr(0, 10);
	if (!isValidDate(date)){
		std::cerr << "Error: invalid date => " << date << std::endl;
		return false;
	}
	std::string ValueNotTrimed = line.substr(pipePos + 1);
	size_t start = ValueNotTrimed.find_first_not_of(" \t");
	if (start == std::string::npos){
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}
	std::string ValueTrimed = ValueNotTrimed.substr(start);
	value = atof(ValueTrimed.c_str());
	if (isValidValue(value) == false)
		return false;
	return true;

}

std::map<std::string, float> loadDatabase(const std::string &dbfile){
	
}

int	parsing(char **av){
	std::ifstream file(av[1]);
	if (!file.is_open()){
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	std::string line;
	std::getline(file, line);
	while(std::getline(file, line)){
		std::string date;
		float value;
		if (parsingline(line, date, value) == false)
			
	}
	return 0;
}
