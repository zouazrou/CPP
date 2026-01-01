#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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

static size_t jacobsthal_int(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    size_t a = 0;
    size_t b = 1;
    for (size_t i = 2; i <= n; ++i)
    {
        size_t c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

static void add_once(std::vector<size_t> &order, std::vector<bool> &used, size_t idx)
{
    if (idx < used.size() && !used[idx])
    {
        used[idx] = true;
        order.push_back(idx);
    }
}

static void ford_johnson_sort(std::vector<int> &container)
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
    std::cout << "\n\nMAIN CHAIN BEFORE SORT: ";
    PrintContainer(mainChain);
    std::cout << "PEND BEFORE SORT: ";
    PrintContainer(pend);
    ford_johnson_sort(mainChain);

    std::vector<int> result = mainChain;
    if (!pend.empty())
    {
        // Insert in Jacobsthal-inspired order. Ensure every index [0..pend.size()-1]
        // appears exactly once (no duplicates, no missing indices).
        std::vector<size_t> order;
        std::vector<bool> used(pend.size(), false);

        add_once(order, used, 0);
        if (pend.size() >= 2)
            add_once(order, used, 1);

        size_t prevJ = 1; // J(2)
        for (size_t k = 3;; ++k)
        {
            size_t j = jacobsthal_int(k);
            if (j >= pend.size())
                break;
            for (size_t idx = j; idx > prevJ; --idx)
                add_once(order, used, idx);
            prevJ = j;
        }
        for (size_t idx = pend.size() - 1; idx > prevJ; --idx)
            add_once(order, used, idx);

        // Safety net: if anything was missed, add remaining indices in order.
        for (size_t idx = 0; idx < pend.size(); ++idx)
            add_once(order, used, idx);

        for (size_t oi = 0; oi < order.size(); ++oi)
        {
            const int value = pend[order[oi]];
            std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), value);
            result.insert(pos, value);
        }
    }

    container.swap(result);
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
    std::cout << "-------- BEFORE FORD-JOHNSON ALGORITHM --------" << std::endl;
    PrintContainer(container);
    ford_johnson_sort(container);
    std::cout << "--------- AFTER FORD-JOHNSON ALGORITHM ---------" << std::endl;
    PrintContainer(container);
    return 0;
}
