#include "../Point.hpp"

Point::Point(): _x(0), _y(0){

}

Point::Point(const float numb_x, const float numb_y): _x(numb_x), _y(numb_y){
}

Point::Point(const Point& other): _x(other._x), _y(other._y){
}

Point& Point::operator=(const Point& other){
	(void)other;
	return *this;
}

Fixed Point::GetX()const{
	return _x;
}

Fixed Point::GetY()const{
	return _y;
}

Point::~Point(){

}
