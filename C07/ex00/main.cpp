#include <iostream>
#include "whatever.hpp"

int main(void)
{
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    float e = 1.5f;
    float f = 2.5f;
    ::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
    std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;
    bool g = true;
    bool h = false;
    ::swap(g, h);
    std::cout << "g = " << g << ", h = " << h << std::endl;
    std::cout << "min( g, h ) = " << ::min(g, h) << std::endl;
    std::cout << "max( g, h ) = " << ::max(g, h) << std::endl;
    double i = 3.14159;
    double j = 3.14158;
    ::swap(i, j);
    std::cout << "i = " << i << ", j = " << j << std::endl;
    std::cout << "min( i, j ) = " << ::min(i, j) << std::endl;
    std::cout << "max( i, j ) = " << ::max(i, j) << std::endl;
    return 0;
}