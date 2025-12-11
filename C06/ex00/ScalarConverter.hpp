#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdlib>

class ScalarConverter
{
private:

    static  int     i;
    static  char    c;
    static  float   f;
    static  double  d;
    ScalarConverter();
    ScalarConverter(const ScalarConverter& s);
    ScalarConverter& operator =(const ScalarConverter& s);
    ~ScalarConverter();
    
    typedef enum    e_types 
    {
        ERROR,
        CHAR,
        INT,
        FLOAT,
        DOUBLE
    }               t_types;

    static bool     isInt(const std::string& s);
    static bool     isChar(const std::string& s);
    static bool     isFloat(const std::string& s);
    static bool     isDouble(const std::string& s);

    static bool     isPseudoliterals(const std::string& s);
    static t_types  getType(const std::string& s);
    static bool     isDecimal(const std::string& num);

    static void     castFromInt(const std::string& s);
    static void     castFromChar(const std::string& s);
    static void     castFromFloat(const std::string& s);
    static void     castFromDouble(const std::string& s);

public:
    static void     convert(std::string str);
};

#endif
