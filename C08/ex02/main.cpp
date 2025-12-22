#include <iostream>
#include <vector>
#include <list>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(30);
    mstack.push(40);
    mstack.push(50);
    //[...]
    mstack.push(1337    );
    // *** Check Normal iterators ***
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << " < ";
        ++it;
    }
    std::cout << std::endl;
    std::stack<int> s(mstack);
    // *** Check Reverse iterators ***
    MutantStack<int>::reverse_iterator rIt = mstack.rbegin();
    MutantStack<int>::reverse_iterator rIte = mstack.rend();
    rIt++;
    rIt--;
    while (rIt != rIte)
    {
        std::cout << *rIt << " < ";
        ++rIt;
    }
    std::cout << std::endl;
    return 0;
}