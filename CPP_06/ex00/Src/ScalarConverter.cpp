#include "../ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){

}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other){
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(){

}

static double parseValue(const std::string &literal, bool &isSpecial){
	if (literal.length() == 2 && !isdigit(literal[0]))
		return static_cast<double>(literal[0]);
	if (literal == "nan" || literal == "nanf"){
		isSpecial = true;
		return std::strtod("nan", NULL);
	}
	if (literal == "inf" || literal == "inff" || literal == "+inf" || literal == "+inff"){
		isSpecial = true;
		return std::strtod("inf", NULL);
	}
	if (literal == "-inf" || literal == "-inff"){
		isSpecial = true;
		return std::strtod("-inf", NULL);
	}
	return std::strtod(literal.c_str(), NULL);
}

static void printChar(double value, bool &isSpecial){
	std::cout << "char: ";
	if (isSpecial || std::isnan(value) ||std::isinf(value))
		std::cout << "impossible";
	else if(value < 0 || value > 127)
		std::cout << "impossible";
	else if (!isprint(static_cast<char>(value)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << std::endl;
}

static void printInt(double value, bool &isSpecial){
	std::cout << "int: ";
	if (isSpecial || std::isnan(value) ||std::isinf(value))
		std::cout << "impossible";
	else if (value < INT_MIN || value > INT_MAX)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

static void printFloat(double value){
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf";
	else if(std::isinf(value))
		std::cout << (value < 0 ? "-inff" : "+inff");
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f";
	std::cout << std::endl;
}

static void printDouble(double value){
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan";
	else if (std::isinf(value))
		std::cout << (value < 0 ? "-inff" : "+inff");
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value);
	std::cout << std::endl;
}

void	ScalarConverter::convert(const std::string &literal){
	bool isSpecial = false;
	double value = parseValue(literal, isSpecial);

	printChar(value, isSpecial);
	printInt(value, isSpecial);
	printFloat(value);
	printDouble(value);
}