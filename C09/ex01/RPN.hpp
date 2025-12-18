#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stdexcept>
# include <stack>

class RPN
{
private:
    // ** Utils **
    static bool    isoperator(char c);
    static int     do_operation(int f, int s, char op);
    static void    ft_pop(int& var, std::stack<int>& s);

public:
    RPN();
    RPN(const RPN& othr);
    RPN& operator =(const RPN& othr);
    ~RPN();


    // ** Main Function **
    static int     eval(std::string& exp);
};

#endif