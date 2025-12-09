#include "utils.hpp"

bool    isChar(const std::string& s)
{
    int sz; 
    
    sz = s.length(); 
    if (s[0] != '\'' || s[sz-1] != '\'')
        return (false);
    if (sz == 4 && s[1] == '\\')
        return (true);
    if (sz == 3)
        return (true);
    return (false);
}

bool    isInt(const std::string& s)
{
    int sz = s.length();
    int i = 0;

    if (s[i] == '-' || s[i] == '+')
        i++;
    if (!sz || sz > 10 )
        return (false); 
    for (; i < sz; i++)
    {
        if (!isdigit(s[i]))
            return (false);
    }
    return (true);
}

static bool isDecimal(const std::string& num)
{
    bool    hasDot = false;
    bool    hasDigits = false;
    size_t  i = 0;

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
    return hasDigits;
}

bool    isFloat(const std::string& s)
{
    if (s == "-inff" || s == "+inff" || s == "nanf")
        return true;
    if (s.empty() || s.back() != 'f')
        return false;
    std::string numPart = s.substr(0, s.length() - 1);
    return (isDecimal(numPart));
}

bool    isDouble(const std::string& str)
{
    return (isDecimal(str));
}

t_types getType(const std::string& str)
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