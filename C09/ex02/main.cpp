#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        PmergeMe::fordJohnson_algorithm(av + 1, ac - 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
