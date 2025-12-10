#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <string>

typedef enum    e_types 
{
    ERROR,
    CHAR,
    INT,
    FLOAT,
    DOUBLE
}               t_types;

bool    isInt(const std::string& s);
bool    isChar(const std::string& s);
bool    isFloat(const std::string& s);
bool    isDouble(const std::string& s);
t_types getType(const std::string& s);

void    castToInt(const std::string& s);
void    castToChar(const std::string& s);
void    castToFloat(const std::string& s);
void    castToDouble(const std::string& s);

#endif
