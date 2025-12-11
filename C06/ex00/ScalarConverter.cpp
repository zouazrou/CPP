#include "ScalarConverter.hpp"

int     ScalarConverter::i;
char    ScalarConverter::c;
float   ScalarConverter::f;
double  ScalarConverter::d;

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& s)
{
    static_cast<void>(s);
}

ScalarConverter& ScalarConverter::operator =(const ScalarConverter& s)
{
    static_cast<void>(s);
    return (*this);
}

ScalarConverter::~ScalarConverter()
{}

// !!!!!!!
bool    ScalarConverter::isChar(const std::string& s)
{
    int sz; 
    
    sz = s.length(); 
    if (sz != 3 || s[0] != '\'' || s[sz-1] != '\'')
        return (false);
    return (true);
}

bool    ScalarConverter::isInt(const std::string& s)
{
    int i = 0;
    int sz = s.length();
    long num;

    if (s[i] == '-' || s[i] == '+')
        i++;
    if (!sz || sz > 11)
        return (false); 
    for (; i < sz; i++)
    {
        if (!isdigit(s[i]))
            return (false);
    }
    num = strtol(s.c_str(), NULL, 10);
    return (!(num > INT_MAX ||  num < INT_MIN));
}

bool    ScalarConverter::isDecimal(const std::string& num)
{
    size_t  i           = 0;
    bool    hasDot      = false;
    bool    hasDigits   = false;

    if (num[i] == '+' || num[i] == '-')
        i++;
    for (; i < num.length(); i++)
    {
        if (num[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        } 
        else if (std::isdigit(num[i]))
            hasDigits = true;
        else
            return false;
    }
    return (hasDigits && hasDot);
}

bool    ScalarConverter::isFloat(const std::string& s)
{
    if (s == "-inff" || s == "+inff" || s == "nanf")
        return true;
    if (s.empty() || s[s.size()-1] != 'f')
        return false;
    std::string numPart = s.substr(0, s.length() - 1);
    return (isDecimal(numPart));
}

bool    ScalarConverter::isDouble(const std::string& str)
{
    if (str == "-inf" || str == "+inf" || str == "nan")
        return true;
    return (isDecimal(str));
}

ScalarConverter::t_types    ScalarConverter::getType(const std::string& str)
{
    if (isInt(str))
        return (INT);
    if (isChar(str))
        return (CHAR);
    if (isFloat(str))
        return (FLOAT);
    if (isDouble(str))
        return (DOUBLE);
    return (ERROR);
}

bool    ScalarConverter::isPseudoliterals(const std::string& s)
{
    return (s == "+inf" || s == "-inf" || s == "nan") ||
           (s == "+inff" || s == "-inff" || s == "nanf");
}

int  CharToInt(const std::string& s)
{
    if (s.length() == 3)
        return static_cast<int>(s[1]);
    if (s.length() == 4 && s[1] == '\\' && s[2] == '\\')
        return (92);
    return (-1);
}

void    ScalarConverter::castFromInt(const std::string& s)
{
    long    num;
    bool    overflow;

    num = strtol(s.c_str(), NULL, 10);
    overflow = false; 
    if (num > INT_MAX || num < INT_MIN)
        overflow = true;
    i = static_cast<int>(num);
    c = static_cast<char>(i);
    f = static_cast<float>(i);
    d = static_cast<double>(i);
    // ? CHAR
    if (!overflow && (num <= CHAR_MAX && num >= 0))
    {
        if (isprint(c))
            std::cout << "char   : '" << c << '\'' << std::endl;
        else
            std::cout << "char   : Non displayable" << std::endl;
    }
    else
        std::cout << "char   : impossible" << std::endl;
    // ? INT
    if (overflow)
        std::cout << "int    : impossible"<< std::endl;
    else
        std::cout << "int    : " << i << std::endl;
    // ? FLOAT
    std::cout << std::fixed << std::setprecision(1) << "float  : " << f << "f" << std::endl;
    // ? DOUBLE
    std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}

void    ScalarConverter::castFromChar(const std::string& s)
{
    c = static_cast<char>(s[1]);
    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);
    // ? CHAR
    std::cout << "char   : '" << c << '\'' << std::endl;
    // ? INT
    std::cout << "int    : " << i << std::endl;
    // ? FLOAT
    std::cout << "float  : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    // ? DOUBLE
    std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}

void    ScalarConverter::castFromFloat(const std::string& s)
{
    f = static_cast<float>(strtof(s.c_str(), NULL));
    c = static_cast<char>(f);
    i = static_cast<int>(f);
    d = static_cast<double>(f);
    // ? CHAR
    if (isPseudoliterals(s) || i > CHAR_MAX || i < 0)
        std::cout << "char   : impossible"<< std::endl;
    else if (isprint(c))
        std::cout << "char   : '" << c << '\'' << std::endl;
    else
        std::cout << "char   : Non displayable" << std::endl;
    // ? INT
    if (isPseudoliterals(s) || f > INT_MAX || f < INT_MIN)
        std::cout << "int    : impossible"<< std::endl;
    else
        std::cout << "int    : " << i << std::endl;
    // ? FLOAT
    std::cout << "float  : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    // ? DOUBLE
    std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}

void    ScalarConverter::castFromDouble(const std::string& s)
{
    d = static_cast<double>(strtod(s.c_str(), NULL));
    c = static_cast<char>(d);
    i = static_cast<int>(d);
    f = static_cast<float>(d);
    // ? CHAR
    if (isPseudoliterals(s) || i > CHAR_MAX || i < 0 || static_cast<double>(i) != d)
        std::cout << "char   : impossible"<< std::endl;
    else if (isprint(c))
        std::cout << "char   : '" << c << '\'' << std::endl;
    else
        std::cout << "char   : Non displayable" << std::endl;
    // ? INT
    if (isPseudoliterals(s) || d > INT_MAX || d < INT_MIN)
        std::cout << "int    : impossible"<< std::endl;
    else
        std::cout << "int    : " << i << std::endl;
    // ? FLOAT
    std::cout << "float  : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    // ? DOUBLE
    std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;
}

void    ScalarConverter::convert(std::string str)
{
    t_types tp = getType(str);

    if (tp == CHAR)
        castFromChar(str);
    else if (tp == INT)
        castFromInt(str);
    else if (tp == FLOAT)
        castFromFloat(str);
    else if (tp == DOUBLE)
        castFromDouble(str);
    else
        std::cout << "Error: Invalid Input" << std::endl;
}
