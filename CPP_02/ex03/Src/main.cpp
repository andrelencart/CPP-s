#include "../Point.hpp"

int main( void ) {

	Point a(15.0f, 0.0f);
	Point b(0.0f, 15.0f);
	Point c(15.0f, 15.0f);

	Point point1(15.0f, 14.0f);
	std::cout << "Point1 ";
	bsp(a, b, c, point1);

	return 0;
}

