#include "Fixed.hpp"

// CONSTRUCTORS

Fixed::Fixed( void ){ 	

	std::cout << "Default constructor called" << std::endl;
	this->_rawValue = 0;
	return ;
}

Fixed::Fixed(const Fixed& toCopy) {

	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

Fixed::Fixed( const int& toCopy ){

	std::cout << "Int constructor called" << std::endl;
	this->_rawValue = toCopy << 8;
	return ;
}
Fixed::Fixed( const float& toCopy ){

	std::cout << "Float constructor called" << std::endl;
	float	toFloat = toCopy * (1 << _bits);
	_rawValue = roundf(toFloat);
	return ;
}

// DESTRUCTOR

Fixed::~Fixed ( void ){

	std::cout << "Destructor called" << std::endl;
	return ;
}

// OPERATOR

Fixed&	Fixed::operator=(const Fixed& Other){

	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &Other)
		this->_rawValue = Other._rawValue;
	return (*this);
}

bool	Fixed::operator==(const Fixed& Other){

		return (_rawValue == Other._rawValue);
}

bool	Fixed::operator>(const Fixed& Other){

		return (_rawValue > Other._rawValue);
}

bool	Fixed::operator<(const Fixed& Other){

		return (_rawValue < Other._rawValue);
}

bool	Fixed::operator<=(const Fixed& Other){

		return (_rawValue <= Other._rawValue);
}

bool	Fixed::operator>=(const Fixed& Other){

		return (_rawValue >= Other._rawValue);
}

bool	Fixed::operator!=(const Fixed& Other){

		return (_rawValue != Other._rawValue);
}

std::ostream& operator<<(std::ostream& os, const Fixed& Other){

	os << (Other.toFloat());
	return (os);
}

// SET AND GET

void	Fixed::setRawBits( int const raw ){

	std::cout << "setRawBits member function called" << std::endl;
	this->_rawValue = raw;
	return ;
}

int		Fixed::getRawBits( void ) const{

	std::cout << "getRawBits member function called" << std::endl;
	return (_rawValue);
}

// TRANFORM

float	Fixed::toFloat( void ) const{

	float scaledValue = static_cast<float>(_rawValue) / (1 << _bits);
    return (scaledValue);
}
int		Fixed::toInt( void ) const{

	return (_rawValue >> _bits);
}
