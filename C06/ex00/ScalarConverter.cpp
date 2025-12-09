#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& s)
{
}

ScalarConverter& ScalarConverter::operator =(const ScalarConverter& s)
{
    return (*this);
}

ScalarConverter::~ScalarConverter()
{}

void    ScalarConverter::convert(std::string str)
{
    t_types tp = getType(str);
}
