#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "color.hpp"

size_t jacobsthal(size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
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

void insert_binary_search(std::vector<int> &mainChain, const std::vector<int> &pend, size_t idx)
{
    const int value = pend[idx];
    std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
    mainChain.insert(pos, value);
}

void ford_johnson_sort_vec(std::vector<int> &container)
{
    if (container.size() < 2)
        return;

    std::vector<int> mainChain;
    std::vector<int> pend;

    for (size_t i = 0; i + 1 < container.size(); i += 2)
    {
        int a = container[i];
        int b = container[i + 1];
        if (a > b)
            std::swap(a, b);
        pend.push_back(a);
        mainChain.push_back(b);
    }
    if ((container.size() % 2) != 0)
        mainChain.push_back(container.back());

    ford_johnson_sort_vec(mainChain);
    
    if (pend.size() >= 1)
        insert_binary_search(mainChain, pend, 0);
    if (pend.size() >= 2)
        insert_binary_search(mainChain, pend, 1);
    size_t prevJ = 1;
    size_t k = 2;
    while (++k)
    {
        size_t last = std::min(pend.size() - 1, jacobsthal(k));
        if (last <= prevJ)
            break;
        for (size_t idx = last; idx > prevJ; --idx)
            insert_binary_search(mainChain, pend, idx);
        prevJ = last;
    }
    container = mainChain;
}

/*
 * MAIN : B1, A1, A2
 * PEND : B2, B3 ...
 */
int main(int ac, char **av)
{
    std::vector<int> container;

    for (int i = 1; i < ac; i++)
    {
        try
        {
            int num = std::atoi(av[i]);
            if (num < 0)
                throw std::invalid_argument("Negative number");
            container.push_back(num);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Error: Invalid input '" << av[i] << "'. Please provide non-negative integers only." << RESET << std::endl;
            return 1;
        }
    }
    std::cout << "          SIZE NUMBERS IS : " << container.size() << std::endl;
    PrintContainer(container);
    ford_johnson_sort_vec(container);
    std::cout << GREEN;
    PrintContainer(container);
    std::cout << RESET;
    return 0;
}
