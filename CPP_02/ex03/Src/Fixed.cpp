#include "../Fixed.hpp"

Fixed::Fixed() : _value(0){
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int conv){
	// std::cout << "Int constructor called" << std::endl;
	_value = conv << this->_FractionalBits;
}

Fixed::Fixed(const float numb){
	// std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(numb * (1 << this->_FractionalBits)));
}

Fixed& Fixed::operator=(const Fixed& other){
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other._value;
	return *this;
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator>(const Fixed& other)const{
	return (_value > other._value);
}

bool Fixed::operator<(const Fixed& other)const{
	return (_value < other._value);
}

bool Fixed::operator==(const Fixed& other)const{
	return (_value == other._value);
}

bool Fixed::operator>=(const Fixed& other)const{
	return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other)const{
	return (_value <= other._value);
}

bool Fixed::operator!=(const Fixed& other)const{
	return (_value != other._value);
}

Fixed Fixed::operator+(const Fixed& other)const{
	return this->_value + other._value;
}

Fixed Fixed::operator-(const Fixed& other)const{
	Fixed result;

	result._value = _value - other._value;
	return result;
}

Fixed Fixed::operator*(const Fixed& other)const{
	Fixed res;
	Fixed tmp;

	tmp._value = this->_value * other._value;
	res._value = tmp._value >> _FractionalBits;
	return res;
}

Fixed Fixed::operator/(const Fixed& other)const{
	if (other._value == 0){
		std::cerr << "Fixed::operator/: division by zero" << std::endl;
		return Fixed(0);
	}
	Fixed res;
	Fixed tmp;

	tmp._value = this->_value << _FractionalBits;
	res._value = tmp._value / other._value;
	return res;
}

Fixed& Fixed::operator++(){
	++_value;
	return (*this);
}

Fixed& Fixed::operator--(){
	--_value;
	return (*this);
}

Fixed Fixed::operator++(int){
	Fixed new_value = *this;
	_value++;
	return new_value;
}

Fixed Fixed::operator--(int){
	Fixed new_value = *this;
	_value--;
	return new_value;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
	if (a._value < b._value)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	if (a._value > b._value)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	if (a._value < b._value)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	if (a._value > b._value)
		return (a);
	else
		return (b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f){
	os << f.toFloat();
	return os;
}


int	Fixed::toInt(void)const{
	return _value / (1 << _FractionalBits);
}

float Fixed::toFloat(void)const{
	return (static_cast<float>(_value) / (static_cast<float>(1 << _FractionalBits)));
}

// int	Fixed::getRawBits(void) const{
// 	std::cout << "getRawBits member function called" << std::endl;
// 	return this->_FractionalBits;
// }

// void	Fixed::setRawBits(int const raw){
// 	std::cout << "setRawBits member function called" << std::endl;
// 	this->_value = raw;
// }
