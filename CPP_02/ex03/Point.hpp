#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point{

	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point(const Point& other);
		Point(const float numb_x, const float numb_y);
		Point& operator=(const Point& other);
		~Point();

		Fixed GetX()const;
		Fixed GetY()const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed GetArea(Point const a, Point const b, Point const c);

#endif