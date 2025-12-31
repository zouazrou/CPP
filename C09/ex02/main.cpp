#include <iostream>
#include <vector>
#include <cmath>
#include "color.hpp"

size_t jacobsthal(size_t n)
{
    // if (n == 0) return 0;
    // if (n == 1) return 1;
    // return (jacobsthal(n-1) + 2*jacobsthal(n-2));

    return ((pow(2, n) - (pow(-1, n))) / 3);
}

template <typename T> void PrintContainer(const T& container)
{
    std::cout << "[";
    for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
    {
        std::cout << *it;
        if (it+1 != container.end())
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

size_t startPair(size_t idx, size_t pairSize)
{
    return (idx - pairSize + 1);
}

size_t endPair(size_t idx)
{
    return (idx + 1);
}


void ford_johnson_alg(std::vector<int> &container, int pair_level)
{
    const size_t units = container.size() / pair_level; // number of full pair_level blocks
    if (units < 2)
        return;

    const size_t limit = units * pair_level;            // ignore leftover remainder
    const size_t step = static_cast<size_t>(2) * pair_level;
    {
        std::cout << RED;
        PrintContainer(container);
        std::cout << RESET;
    }
    for (size_t start = 0; start + step <= limit; start += step)
    {
        size_t first  = start + pair_level - 1;
        size_t second = start + step - 1;

        if (container[first] > container[second])
        {
            std::swap_ranges(container.begin() + start,
                             container.begin() + start + pair_level,
                             container.begin() + start + pair_level);
        }
    }
    {
        std::cout << GREEN;
        PrintContainer(container);
        std::cout << RESET;
    }
    
    ford_johnson_alg(container, pair_level * 2);
    // std::vector<Iterator> pendC, mainC;

}
/*
 * MAIN : B1, A1, A2
 * PEND : B2, B3 ...
 */
int main()
{
    std::vector<int> container;
    int arr[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};

    for (int i = 0; i < 22; i++)
        container.push_back(arr[i]);

    std::cout << "          SIZE NUMBERS IS : " << container.size() << std::endl;
    ford_johnson_alg(container, 1);
    return 0;
}
