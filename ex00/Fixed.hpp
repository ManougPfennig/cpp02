#include <iostream>

class Fixed {

private :

		int					_rawValue;
		const static int	_bits = 8; // 8 des 32 bits de l'int seront reserve a la partie fractionnaire.

public :

		Fixed( void );
		Fixed( const Fixed& toCopy );
		~Fixed( void );
		Fixed& operator=( const Fixed& Other );
		
		void	setRawBits( int const raw );
		int		getRawBits( void ) const;

};
