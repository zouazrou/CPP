#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T, typename C=std::deque<T> >
class MutantStack : public std::stack<T, C>
{
public:
    MutantStack() : std::stack<T, C>()
    {}

    MutantStack(const MutantStack& othr) : std::stack<T, C>(othr)
    {}

    MutantStack& operator =(const MutantStack& othr)
    {
        if (this != &othr)
            std::stack<T, C>::operator=(othr);
        return (*this);
    }

    ~MutantStack()
    {}
    
    // ******
    
    typedef typename C::iterator                iterator;
    typedef typename C::const_iterator          const_iterator;
    typedef typename C::reverse_iterator        reverse_iterator;
    typedef typename C::const_reverse_iterator  const_reverse_iterator;
    
    // ****** Noraml iterators ****** 
    iterator begin()
    {
        return (this->c.begin());
    }
    
    const_iterator begin() const
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }

    const_iterator end() const
    {
        return this->c.end();
    }

    // ****** Reverse iterators ****** 
    reverse_iterator rbegin()
    {
        return this->c.rbegin();
    }

    const_reverse_iterator rbegin() const
    {
        return this->c.rbegin();
    }

    reverse_iterator rend()
    {
        return this->c.rend();
    }

    const_reverse_iterator  rend() const
    { 
        return this->c.rend();
    }
};

#endif