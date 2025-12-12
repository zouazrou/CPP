#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename A, typename B>
void iter(A *arr, size_t s, B fn)
{
    if (!arr || !fn)
        return ;
    for (size_t i = 0; i < s; i++)
        fn(arr[i]);
}

#endif