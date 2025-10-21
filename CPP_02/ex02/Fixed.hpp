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

		bool operator>(const Fixed& other)const;
		bool operator<(const Fixed& other)const;
		bool operator==(const Fixed& other)const;
		bool operator>=(const Fixed& other)const;
		bool operator<=(const Fixed& other)const;
		bool operator!=(const Fixed& other)const;

		Fixed operator+(const Fixed& other)const;
		Fixed operator-(const Fixed& other)const;
		Fixed operator*(const Fixed& other)const;
		Fixed operator/(const Fixed& other)const;

		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b); 
		static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif