#include "../Bureaucrat.hpp"

int main(void){

	try{
		Bureaucrat A("RALPH", 1);
		std::cout << A << std::endl;
		A.IncrementGrade(1);
		std::cout << A << std::endl;
		A.DecrementGrade(4);
		std::cout << A << std::endl;

	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

}