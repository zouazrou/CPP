#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void)
{
    // **Test to check Vector 
    std::vector<int> vec;
    
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    try
    {
        std::cout << (*easyfind(vec, 30)) << " is found!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // **Test to check List 
    std::list<int> lst;

    lst.push_back(1);
    lst.push_back(3);
    lst.push_back(-42);
    try
    {
        std::cout << (*easyfind(lst, 30)) << " is found!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
