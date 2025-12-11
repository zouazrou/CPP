#include <iostream>
#include "utils.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    Base    *basePtr;
    basePtr = generate();
    identify(basePtr);
    identify(*basePtr);
    delete basePtr;
    return 0;
}