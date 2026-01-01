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

void insert_binary_search_vec(std::vector<unsigned int> &mainChain, const std::vector<unsigned int> &pend, size_t idx)
{
    int value = pend[idx];
    std::vector<unsigned int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
    mainChain.insert(pos, value);
}

void ford_johnson_sort_vec(std::vector<unsigned int> &container)
{
    if (container.size() < 2)
        return;

    unsigned int a, b;
    size_t prevJB, last, n;
    std::vector<unsigned int>    mainChain, pend;

    for (size_t i = 0; i + 1 < container.size(); i += 2)
    {
        a = container[i];
        b = container[i + 1];
        if (a > b)
            std::swap(a, b);
        pend.push_back(a);
        mainChain.push_back(b);
    }
    if ((container.size() % 2) != 0)
        mainChain.push_back(container.back());

    ford_johnson_sort_vec(mainChain);
    
    if (pend.size() >= 1)
        insert_binary_search_vec(mainChain, pend, 0);
    if (pend.size() >= 2)
        insert_binary_search_vec(mainChain, pend, 1);
    prevJB = 1; 
    n = 3;
    while (n)
    {
        last = std::min(pend.size() - 1, jacobsthal(n++));
        if (last <= prevJB)
            break;
        for (size_t i = last; i > prevJB; --i)
            insert_binary_search_vec(mainChain, pend, i);
        prevJB = last;
    }
    container = mainChain;
}

/*
 * MAIN : B1, A1, A2
 * PEND : B2, B3 ...
 */
int main(int ac, char **av)
{
    std::vector<unsigned int> container;

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
