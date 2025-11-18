#include "../Bureaucrat.hpp"
#include "../Form.hpp"

int main(void){

	try{
		Bureaucrat A("RALPH", 50);
		Form Low("LowForm", 20, 150);
		std::cout << A << std::endl;
		std::cout << Low << std::endl;
		A.SignForm(Low);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

}