#include <iostream>

#define DATABASE_NAME "data.csv"

int main(int ac, char *av[])
{
    if (ac != 2)
        std::cerr << "./btw [filename]";
    
    return 0;
}
