#include <iostream>
#include <cmath>

class Fixed {

private :

		int					_rawValue;
		const static int	_bits = 8; // bits reserve a la partie fractionnaire.

public :

		Fixed( void );
		Fixed( const Fixed& toCopy );
		Fixed( const int& toCopy );
		Fixed( const float& toCopy );
		~Fixed( void );
		Fixed&	operator=( const Fixed& Other );

		//operateur de comparaison
		bool	operator==( const Fixed& Other ) const;
		bool	operator>( const Fixed& Other ) const;
		bool	operator<( const Fixed& Other ) const;
		bool	operator<=( const Fixed& Other ) const;
		bool	operator>=( const Fixed& Other ) const;
		bool	operator!=( const Fixed& Other ) const;

		//operateur arithmetique + - * /
		Fixed	operator+(const Fixed& Other) const;
		Fixed	operator-(const Fixed& Other) const;
		Fixed	operator*(const Fixed& Other) const;
		Fixed	operator/(const Fixed& Other) const;

		//operateur ++ et --
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);

		void	setRawBits( int const raw );
		int		getRawBits( void ) const;

		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed	min(Fixed& a, Fixed& b);
		static Fixed	min(const Fixed& a, const Fixed& b);
		static Fixed	max(Fixed& a, Fixed& b);
		static Fixed	max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& Other);