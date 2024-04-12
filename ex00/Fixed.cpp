#include "Fixed.hpp"

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

Fixed::~Fixed ( void ){

	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed& Fixed::operator=(const Fixed& Other){

	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &Other)
		this->_rawValue = Other.getRawBits();
	return (*this);
}

void	Fixed::setRawBits( int const raw ){

	std::cout << "setRawBits member function called" << std::endl;
	this->_rawValue = raw;
	return ;
}

int		Fixed::getRawBits( void ) const{

	std::cout << "getRawBits member function called" << std::endl;
	return (_rawValue);
}
