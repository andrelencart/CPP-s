
#include <iostream>

int	main(void)
{
	std::string originSTR;
	std::string *originPTR = &originSTR;
	std::string &originREF = originSTR;

	originSTR = "HI THIS IS BRAIN";
	// *originPTR = originSTR;
	std::cout << "- The Memory Address of OriginStr: " << &originSTR << std::endl;
	std::cout << "- The Memory Address held by OriginPTR: " << originPTR << std::endl;
	std::cout << "- The Memory Address held by OriginREF: " << &originREF << std::endl;
	std::cout << std::endl;
	std::cout << "- The Value of the OriginStr: " << originSTR << std::endl;
	std::cout << "- The Value Pointed to by OriginPTR: " << *originPTR << std::endl;
	std::cout << "- The Value Referenced to by OriginREF: " << originREF << std::endl;

}