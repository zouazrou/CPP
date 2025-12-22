#include "Span.hpp"

Span::Span(size_t N) : N(N)
{}

Span::Span(const Span& othr) : N(othr.N), myContainer(othr.myContainer)
{}

Span&   Span::operator= (const Span& othr)
{
    if (this == &othr)
        return (*this);
    this->N = othr.N;
    this->myContainer = othr.myContainer;
    return (*this);
}

Span::~Span()
{}

void    Span::addNumber(int num)
{
    if (this->myContainer.size() == this->N)
        throw std::runtime_error("multiset is full!");
    this->myContainer.insert(num);
}
int Span::shortestSpan(void)
{
    int Min = INT_MAX;
    int diff;

    if (myContainer.size() < 2)
        throw std::runtime_error("size less then 2");
        
    std::multiset<int>::iterator NextIt = myContainer.begin();
    std::multiset<int>::iterator it = NextIt++;

    while (NextIt != myContainer.end())
    {
        diff = *(NextIt++) - *(it++); 
        if (diff < Min)
            Min = diff;
    }
    return (Min);
}

// * return (begin() - end()-1)
int Span::longestSpan(void)
{
    if (myContainer.size() < 2)
        throw std::runtime_error("size less then 2");
    return (*myContainer.rbegin() - *myContainer.begin());
}

