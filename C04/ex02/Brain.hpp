#ifndef BRAIN_HPP
# define BRAIN_HPP

#define SIZE_ARR 100

#include <iostream>

class Brain
{
private:
    std::string ideas[SIZE_ARR];

public:
    Brain();
    Brain(const Brain &src);
    Brain &operator=(const Brain &src);
    ~Brain();
};

#endif