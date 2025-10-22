
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 num;
        static const int    numFracBits;

    public:
        Fixed();

        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &x);
        Fixed& operator= (const Fixed& f);
        ~Fixed();
        
        float toFloat( void ) const;
        int toInt( void ) const;
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};




#endif