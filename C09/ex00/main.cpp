#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "./btw [filename]\n";
        return 1;
    }
    try
    {
        BitcoinExchange obj;
        obj.Binance(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
