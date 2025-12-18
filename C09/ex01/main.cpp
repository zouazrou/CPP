#include "RPN.hpp"
#include <iostream>

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "./RPN [exp]\n";
        return (1);
    }
    std::string exp = av[1];

    try
    {
        std::cout << RPN::eval(exp) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
