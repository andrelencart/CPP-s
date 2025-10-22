#include "../Point.hpp"

Fixed GerArea(Point const a, Point const b, Point const c){
	Fixed delta;

	delta = a.GetX() * ((b.GetY() - c.GetY())) + b.GetX() * ((c.GetY() - a.GetY()))
			+ c.GetX() * ((a.GetY() - b.GetY()));
	return ((delta < Fixed(0)) ? delta * Fixed(-1) : delta);
}


bool bsp( Point const a, Point const b, Point const c, Point const point){

}