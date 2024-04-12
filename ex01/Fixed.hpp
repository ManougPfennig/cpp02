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

		// operateur de comparaison
		bool	operator==( const Fixed& Other );
		bool	operator>( const Fixed& Other );
		bool	operator<( const Fixed& Other );
		bool	operator<=( const Fixed& Other );
		bool	operator>=( const Fixed& Other );
		bool	operator!=( const Fixed& Other );

		//operateur arithmetique
		int		

		void	setRawBits( int const raw );
		int		getRawBits( void ) const;

		float	toFloat( void ) const;
		int		toInt( void ) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& Other);