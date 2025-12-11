#include "utils.hpp"
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base    *generate(void)
{
    int val;

    srand(time(NULL));
    val = rand() % 3;
    if (val == 0)
    {
        std::cout << "Generated A" << std::endl;
        return (new A);
    }
    if (val == 1)
    {
        std::cout << "Generated B" << std::endl;
        return (new B);
    }
    std::cout << "Generated C" << std::endl;
    return (new C);
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "type : A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "type : B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "type : C" << std::endl;
    else
        std::cout << "I don't know -_-" << std::endl;
}

void    identify(Base& p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << "type : A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "type : B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "type : C" << std::endl;
    else
        std::cout << "I don't know -_-" << std::endl;
}

// ! RTTI (Run-Time Type Information) in C++