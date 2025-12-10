#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
        return (1);
    ScalarConverter::convert(av[1]);
    // if (isChar(av[1]))
    //     std::cout << "is char" << std::endl;
    // else if (isInt(av[1]))
    //     std::cout << "is int" << std::endl;
    // else if (isFloat(av[1]))
    //     std::cout << "is float" << std::endl;
    // else if (isDouble(av[1]))
    //     std::cout << "is Double" << std::endl;
    // else
    //     std::cout << "waaa3" << std::endl;
    
    return 0;
}
