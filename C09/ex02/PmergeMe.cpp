#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    static_cast<void>(other);
}

PmergeMe& PmergeMe::operator= (const PmergeMe &other)
{
    static_cast<void>(other);
    return *this;
}

PmergeMe::~PmergeMe()
{}

// *****************************************

size_t PmergeMe::jacobsthal(size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::ParseInput(char **list, size_t size, std::deque<uint> &dq, std::vector<uint> &vc)
{
    double  num;
    char    *ptr;

    if (size < 2)
        throw std::invalid_argument("Error: Input size must be at least 2");
    for (size_t i = 0; i < size; i++)
    {
        num = std::strtod(list[i], &ptr);
        if (*ptr != '\0' || num < 0 || num > INT_MAX)
            throw std::invalid_argument("Error: Must be positive integers only");
        dq.push_back(static_cast<uint>(num));
        vc.push_back(static_cast<uint>(num));
    }
}

void PmergeMe::sort_vec(std::vector<uint> &container)
{
    if (container.size() < 2)
        return;

    uint                a, b;
    size_t              prevJB, last, n;
    std::vector<uint>   mainChain, pend;

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

    sort_vec(mainChain);
    
    if (pend.size() >= 1)
        binary_search_insertion(mainChain, pend, 0);
    if (pend.size() >= 2)
        binary_search_insertion(mainChain, pend, 1);
    prevJB = 1; 
    n = 3;
    while (n)
    {
        last = std::min(pend.size() - 1, jacobsthal(n++));
        if (last <= prevJB)
            break;
        for (size_t i = last; i > prevJB; --i)
            binary_search_insertion(mainChain, pend, i);
        prevJB = last;
    }
    container = mainChain;
}

void PmergeMe::sort_deq(std::deque<uint> &container)
{
    if (container.size() < 2)
        return;

    uint                a, b;
    size_t              prevJB, last, n;
    std::deque<uint>   mainChain, pend;

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

    sort_deq(mainChain);
    
    if (pend.size() >= 1)
        binary_search_insertion(mainChain, pend, 0);
    if (pend.size() >= 2)
        binary_search_insertion(mainChain, pend, 1);
    prevJB = 1; 
    n = 3;
    while (n)
    {
        last = std::min(pend.size() - 1, jacobsthal(n++));
        if (last <= prevJB)
            break;
        for (size_t i = last; i > prevJB; --i)
            binary_search_insertion(mainChain, pend, i);
        prevJB = last;
    }
    container = mainChain;
}

void PmergeMe::fordJohnson_algorithm(char **list, size_t size)
{
    std::deque<uint>    dq;
    std::vector<uint>   vc;
    std::clock_t        start, end;
    double              duration;

    ParseInput(list, size, dq, vc);
    std::cout << RED << "==Before Soring==" << RESET << std::endl;
    PrintContainer(vc);

    start = std::clock();
    sort_deq(dq);
    end = std::clock();
    std::cout << GREEN << "==After Soring==" << RESET << std::endl;

    PrintContainer(dq);
    duration = static_cast<double>(end - start);
    std::cout << CYAN << "Time to process a range of " << size << " elements with std::vector : " << std::fixed << std::setprecision(4)  << duration << " us" << RESET << std::endl;

    start = std::clock();
    sort_vec(vc);
    end = std::clock();
    duration = static_cast<double>(end - start);
    std::cout << MAGENTA << "Time to process a range of " << size << " elements with std::deque : " << std::fixed << std::setprecision(4)  << duration << " us" << RESET << std::endl;
}

