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

//OPERATOR ++ AND --

Fixed	Fixed::operator++(){

	this->_rawValue += (1 << 8);
	return (*this);
}

Fixed	Fixed::operator++(int n){

	Fixed	temp = *this;
	temp._rawValue += (1 << 8);
	return (temp);
}

Fixed	Fixed::operator--(){

	this->_rawValue -= (1 << 8);
	return (*this);
}

Fixed	Fixed::operator--(int n){

	Fixed	temp = *this;
	temp._rawValue -= (1 << 8);
	return (temp);
}

// OPERATOR EQUAL

Fixed&	Fixed::operator=(const Fixed& Other){

	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &Other)
		this->_rawValue = Other._rawValue;
	return (*this);
}

// COMPARE OPERATOR

bool	Fixed::operator==(const Fixed& Other) const{

		return (_rawValue == Other._rawValue);
}

bool	Fixed::operator>(const Fixed& Other) const{

		return (_rawValue > Other._rawValue);
}

bool	Fixed::operator<(const Fixed& Other) const{

		return (_rawValue < Other._rawValue);
}

bool	Fixed::operator<=(const Fixed& Other) const{

		return (_rawValue <= Other._rawValue);
}

bool	Fixed::operator>=(const Fixed& Other) const{

		return (_rawValue >= Other._rawValue);
}

bool	Fixed::operator!=(const Fixed& Other) const{

		return (_rawValue != Other._rawValue);
}

// ARITHMETIC OPERATOR

Fixed Fixed::operator+(const Fixed& Other) const{

	Fixed	temp(*this);

	temp._rawValue += Other._rawValue;
	return (temp);
}

Fixed Fixed::operator-(const Fixed& Other) const{

	Fixed	temp(*this);

	temp._rawValue -= Other._rawValue;
	return (temp);
}

Fixed Fixed::operator*(const Fixed& Other) const{

	signed long int result = _rawValue * Other._rawValue;
	result >>= _bits;

	Fixed multiplied;
	multiplied.setRawBits(result);
	return (multiplied);
}

Fixed Fixed::operator/(const Fixed& Other) const{

	signed long int numerator = _rawValue << _bits;
	signed long int result = numerator / Other._rawValue;

    Fixed divided;
    divided.setRawBits(result);
    return (divided);
}

// REDIRECT OPERATOR

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

// MIN AND MAX FUNCTIONS

Fixed	Fixed::min(Fixed& a, Fixed& b){

	if (a > b)
		return (b);
	return (a);
}

Fixed	Fixed::min(const Fixed& a, const Fixed& b){

	if (a > b)
		return (b);
	return (a);
}

Fixed	Fixed::max(Fixed& a, Fixed& b){

	if (a < b)
		return (b);
	return (a);
}

Fixed	Fixed::max(const Fixed& a, const Fixed& b){

	if (a < b)
		return (b);
	return (a);
}

// TRANFORM

float	Fixed::toFloat( void ) const{

	float scaledValue = static_cast<float>(_rawValue) / (1 << _bits);
    return (scaledValue);
}
int		Fixed::toInt( void ) const{

	return (_rawValue >> _bits);
}
