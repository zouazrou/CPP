#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char *av[])
{
    (void)av;
    if (ac != 2)
    {
        std::cerr << "./btw [filename]\n";
        return 1;
    }
    BitcoinExchange obj;

    return 0;
}
