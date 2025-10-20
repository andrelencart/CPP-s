#include "../Fixed.hpp"

Fixed::Fixed() : _value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
}

Fixed::Fixed(const int conv){
	std::cout << "Int constructor called" << std::endl;
	_value = conv << this->_FractionalBits;
}

Fixed::Fixed(const float numb){
	std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(numb * (1 << this->_FractionalBits)));
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other._value;
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::toInt(void)const{
	return _value / (1 << _FractionalBits);
}

float Fixed::toFloat(void)const{
	return (static_cast<float>(_value) / (static_cast<float>(1 << _FractionalBits)));
}

std::ostream& operator<<(std::ostream& os, const Fixed& f){
	os << f.toFloat();
	return os;
}

// int	Fixed::getRawBits(void) const{
// 	std::cout << "getRawBits member function called" << std::endl;
// 	return this->_FractionalBits;
// }

// void	Fixed::setRawBits(int const raw){
// 	std::cout << "setRawBits member function called" << std::endl;
// 	this->_value = raw;
// }
