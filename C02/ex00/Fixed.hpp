
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 num;
        static const int    numFracBits;

    public:
        Fixed();                            // ! Default Constructor
        Fixed(const Fixed &x);              // ! Copy Constructor
        Fixed& operator= (const Fixed& f);  // ! Copy assignment operator
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};




#endif