#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& s)
{
    (void)s;
}

ScalarConverter& ScalarConverter::operator =(const ScalarConverter& s)
{
    (void)s;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{}

void    ScalarConverter::convert(std::string str)
{
    t_types tp = getType(str);

    if (tp == ERROR)
    {
        std::cout << "Error" << std::endl;
        return ;
    }
    castToChar(str);
    castToInt(str);
    castToFloat(str);
    castToDouble(str);
}
