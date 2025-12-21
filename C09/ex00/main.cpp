#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cerr << "./btw [filename]\n";
        return 1;
    }
    BitcoinExchange obj;

    obj.Binance(av[1]);
    // std::string dt = "2012-0-11";
    // if (obj.isValidDate(dt))
    //     std::cout << "Valid Date\n";
    // else
    //     std::cout << "Invalid Date\n";  
    // obj.Binance(av[1]);
    return 0;
}
