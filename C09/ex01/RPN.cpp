#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN& othr)
{
    static_cast<void>(othr);
}

RPN& RPN::operator =(const RPN& othr)
{
    if (this == &othr)
        return (*this);
    return (*this);
}

RPN::~RPN()
{}

int    RPN::eval(std::string& exp)
{
    std::stack<int> Stack;
    size_t sz = exp.length();
    int     f_operand, s_operand, resutl;
    char    c;

    for (size_t i = 0; i < sz; i++)
    {
        c = exp[i];
        if (isspace(c))
            continue;
        else if (isdigit(c))
            Stack.push(static_cast<int>(c-'0'));
        else
        {
            ft_pop(s_operand, Stack);
            ft_pop(f_operand, Stack);
            resutl = do_operation(f_operand, s_operand, c);
            Stack.push(resutl);
        }
    }
    ft_pop(resutl, Stack);
    if (!Stack.empty())
        throw (std::runtime_error("Error"));
    return (resutl);
}

bool    RPN::isoperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int     RPN::do_operation(int f, int s, char opr)
{
    switch (opr)
    {
    case ('+'):
        return (f + s);
    case ('-'):
        return (f - s);
    case ('*'):
        return (f * s);
    case ('/'):
        if (!s) throw (std::runtime_error("Error"));
        return (f / s);
    default :
        throw (std::runtime_error("Error"));
    }
    return (0);
}

void    RPN::ft_pop(int& var, std::stack<int>& s)
{
    if (s.empty())
        throw(std::runtime_error("Error"));
    var = s.top();
    s.pop();
}
