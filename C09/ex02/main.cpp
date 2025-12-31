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

size_t startPair(size_t idx, size_t pairSize)
{
    return (idx - pairSize + 1);
}

size_t endPair(size_t idx)
{
    return (idx + 1);
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

static void ford_johnson_sort(std::vector<int> &v)
{
    if (v.size() < 2)
        return;

    std::vector<int> mainChain;
    std::vector<int> pend;

    for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
        int a = v[i];
        int b = v[i + 1];
        if (a > b)
            std::swap(a, b);
        pend.push_back(a);
        mainChain.push_back(b);
    }
    if ((v.size() % 2) != 0)
        mainChain.push_back(v.back());

    ford_johnson_sort(mainChain);

    std::vector<int> result = mainChain;
    if (!pend.empty())
    {
        // Insert in Jacobsthal-inspired order (correctness doesn't depend on the order).
        std::vector<size_t> order;
        order.push_back(0);

        size_t prevJ = 1; // J(2)
        for (size_t k = 3;; ++k)
        {
            size_t j = jacobsthal_int(k);
            if (j >= pend.size())
                break;
            for (size_t idx = j; idx > prevJ; --idx)
                order.push_back(idx);
            prevJ = j;
        }
        for (size_t idx = pend.size() - 1; idx + 1 > prevJ; --idx)
            order.push_back(idx);

        for (size_t oi = 0; oi < order.size(); ++oi)
        {
            const int value = pend[order[oi]];
            std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), value);
            result.insert(pos, value);
        }
    }

    v.swap(result);
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
    std::cout << "-------- BEFORE FORD-JOHNSON ALGORITHM --------" << std::endl;
    PrintContainer(container);
    ford_johnson_sort(container);
    std::cout << "--------- AFTER FORD-JOHNSON ALGORITHM ---------" << std::endl;
    PrintContainer(container);
    return 0;
}
