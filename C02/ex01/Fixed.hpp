
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 num;
        static const int    numFracBits;

    public:
        Fixed();
        Fixed(int num);
        Fixed(const Fixed &x);
        Fixed& operator= (const Fixed& f);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};




#endif