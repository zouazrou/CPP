#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstddef>

template <typename T>class Array
{
private:
    T *_arr;
    size_t _size;
public:
    Array() : _arr(NULL), _size(0)
    {}

    Array(const unsigned int size) : _arr(new T[size]()), _size(size)
    {}

    Array(const Array& othr)
    {
        this->_arr = new T[othr.size()];
        _size = othr.size();
        for (unsigned int  i = 0; i < this->_size; i++)
            this->_arr[i] = othr._arr[i];
    }

    Array&  operator =(const Array& othr)
    {
        if (this == &othr)
            return (*this);
        delete[] this->_arr;
        this->_arr = new T[othr.size()];
        _size = othr.size();
        for (unsigned int  i = 0; i < this->_size; i++)
            this->_arr[i] = othr._arr[i];
        return (*this);
    }

    ~Array()
    {
        delete[] _arr;
    }

    T& operator [](unsigned int index) 
    {
        if (index >= this->_size)
            throw (std::out_of_range("Error : Index out of range"));
        return (this->_arr[index]);
    }

    const T& operator [](unsigned int index) const 
    {
        if (index >= this->_size)
            throw (std::out_of_range("Error : Index out of range"));
        return (this->_arr[index]);
    }

    unsigned int size(void) const
    {
        return (this->_size);
    }
};

#endif