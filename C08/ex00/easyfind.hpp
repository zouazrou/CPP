#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename    T::iterator    easyfind(T& c, int s)
{
    typename T::iterator it = std::find(c.begin(), c.end(), s);
    if (it == c.end())
        throw std::runtime_error("Error : No occurrence is found!");
    return (it);
}

#endif