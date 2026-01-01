#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <ctime>
#include <iomanip>

typedef unsigned int uint;

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

class PmergeMe
{
private:
    template <typename T>
    static void PrintContainer(const T& container)
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

    template <typename T>
    static void binary_search_insertion(T& mainChain, const T& pend, size_t idx)
    {
        int value = pend[idx];
        typename T::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(pos, value);
    }

    static  size_t  jacobsthal(size_t n);
    static  void    sort_deq(std::deque<uint> &container);
    static  void    sort_vec(std::vector<uint> &container);
    static  void    ParseInput(char **list, size_t size, std::deque<uint> &dq, std::vector<uint> &vc);


public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe& operator= (const PmergeMe &other);
    ~PmergeMe();
    
    // *****************************************
    static void fordJohnson_algorithm(char **list, size_t size);
    void ParseInput(size_t size, double &num, char **list, char *&ptr, std::deque<uint> &dq, std::vector<uint> &vc);
};



#endif