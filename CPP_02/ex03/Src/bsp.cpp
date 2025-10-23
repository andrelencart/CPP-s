#include "../Point.hpp"

Fixed GetArea(Point const a, Point const b, Point const c){
	Fixed area;

	area = a.GetX() * (b.GetY() - c.GetY())
			+ b.GetX() * (c.GetY() - a.GetY())
			+ c.GetX() * (a.GetY() - b.GetY());
	Fixed absArea = (area < 0) ? area * -1 : area;
	return (absArea / 2);
}


bool bsp( Point const a, Point const b, Point const c, Point const point){
	Fixed BigArea = GetArea(a, b, c);
	Fixed Area1 = GetArea(a, b, point);
	Fixed Area2 = GetArea(b, c, point);
	Fixed Area3 = GetArea(c, a, point);

	if (Area1 == Fixed(0) || Area2 == Fixed(0) || Area3 == Fixed(0)){
		std::cout << "is an Edge or Vertex!!" << std::endl;
		return false;
	}
	if ((Area1 + Area2 + Area3) != BigArea){
		std::cout << "is Outside!!" << std::endl;
		return false;
	}
	return (std::cout << "is Inside!!" << std::endl, true);
}