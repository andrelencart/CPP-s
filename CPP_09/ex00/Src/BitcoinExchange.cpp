#include "../BitcoinExchange.hpp"

bool isValidDate(const std::string& date){
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++){
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(static_cast<unsigned char>(date[i])))
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
		case 2: {
			bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
			int maxDay;
			if (isLeap)
				maxDay = 29;
			else
				maxDay = 28;
			if (day > maxDay)
				return false;
			break;
		}
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

static bool parseFloatStrict(const std::string& s, float &out){
	char *end = NULL;
	out = static_cast<float>(strtod(s.c_str(), &end));
	if (end == s.c_str() || *end != '\0')
		return false;
	return true;
}

bool parsingline(const std::string &line, std::string &date, float &value){
	size_t pipePos = line.find('|');
	if (pipePos == std::string::npos || line.size() < 14 || line[10] != ' ' || line[11] != '|' || line[12] != ' '){
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
	if (!parseFloatStrict(ValueTrimed, value)){
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}
	if (isValidValue(value) == false)
		return false;
	return true;

}

std::map<std::string, float> loadDatabase(const std::string &dbfile){
	std::map<std::string, float> db;
	std::ifstream file(dbfile.c_str());

	if (!file.is_open()){
		std::cerr << "Error: Could not open Database File!" << std::endl;
		return db;
	}
	std::string line;
	std::getline(file, line);
	while(std::getline(file, line)){
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;
		std::string date = line.substr(0, commaPos);
		float rate;
		std::string rateStr = line.substr(commaPos + 1);
		if (!parseFloatStrict(rateStr, rate))
			continue;
		if (!isValidDate(date))
			continue;
		db[date] = rate;
	}
	return db;
}

float FindExchangeRate(const std::map<std::string, float> &db, const std::string &date){
	std::map<std::string, float>::const_iterator it = db.upper_bound(date);

	if (it == db.begin())
		return -1;
	--it;
	return it->second;
}

int	parsing(char **av){
	std::map<std::string, float> db = loadDatabase("data.csv");
	if (db.empty())
		return 1;
	std::ifstream file(av[1]);
	if (!file.is_open()){
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	std::string line;
	if (!std::getline(file, line) || line != "date | value"){
		std::cerr << "Error: invalid header format. Expected 'date | value'" << std::endl;
		return 1;
	}
	while(std::getline(file, line)){
		std::string date;
		float value;
		if (parsingline(line, date, value) == false)
			continue ;
		float rate = FindExchangeRate(db, date);
		if (rate < 0){
			std::cerr << "Error: " << date << " not in the database!" << std::endl;
			continue ;
		}
		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
	return 0;
}
