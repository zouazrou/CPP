#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        ScalarConverter::convert(av[1]);
        return (1);
    }
    ScalarConverter::convert("0");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("'a'");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("42");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("42.0f");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("42.0");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("nan");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("nanf");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("+inf");
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << "---------------------" << std::endl;
    std::cout << "---------------------" << std::endl;
    ScalarConverter::convert("-inff");
    return 0;
}