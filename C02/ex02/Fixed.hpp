
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 num;
        static const int    numFracBits;
        static const int    numFracBits;

    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &x);
        Fixed& operator= (const Fixed& f);
        ~Fixed();
        
        float   toFloat( void ) const;
        int     toInt( void ) const;
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );

        // ! Comparison operators
        bool    operator>(const Fixed& f) const;
        bool    operator<(const Fixed& f) const;
        bool    operator>=(const Fixed& f) const;
        bool    operator<=(const Fixed& f) const;
        bool    operator==(const Fixed& f) const;
        bool    operator!=(const Fixed& f) const;

        // ! arithmetic operators
        Fixed operator+(const Fixed& f) const;
        Fixed operator-(const Fixed& f) const;
        Fixed operator*(const Fixed& f) const;
        Fixed operator/(const Fixed& f) const;

        // ! Increament & Decreament
        Fixed   operator++();
        Fixed   operator--();
        // Fixed&   operator++();
        // Fixed&   operator--();

        // ! Static fucntion
        static Fixed& min(Fixed& f1, Fixed& f2);
        static Fixed& min(const Fixed& f1, const Fixed& f2);
        static Fixed& max(Fixed& f1, Fixed& f2);
        static Fixed& max(const Fixed& f1, const Fixed& f2);
};

std::ostream&   operator<<(std::ostream& OUT, Fixed const& f);

#endif