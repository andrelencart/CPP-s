#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{

	private:
		int	_value;
		static const int _FractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator = (const Fixed& other);
		~Fixed();
		
		Fixed(const int conv);
		Fixed(const float numb);

		float toFloat( void ) const;
		int toInt( void ) const;
		// int getRawBits( void ) const;
		// void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif