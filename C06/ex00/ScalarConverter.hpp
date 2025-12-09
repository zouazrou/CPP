#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include "utils.hpp"

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& s);
    ScalarConverter& operator =(const ScalarConverter& s);
public:
    ~ScalarConverter();

    static void convert(std::string str);
};

#endif
