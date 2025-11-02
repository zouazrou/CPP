#include <iostream>

class A
{
private:
    int b;
public:
    A();
    A(int n);
    A(const A& src);
    A& operator =(const A& src);
    ~A();
};
A::A(int n): b(n){
    std::cout << "Param constructor" << std::endl;
}

A::A() : b(0)
{
    std::cout << "Default constructor" << std::endl;
}

A::A(const A& src)
{
    std::cout << "Copy constructor" << std::endl;
    this->b = src.b;   
}
A& A::operator =(const A& src)
{
    std::cout << "assignemt constructor" << std::endl;
    this->b = src.b;
    return (*this);
}

A::~A()
{}

int main(int argc, char const *argv[])
{
    A obj(432);
    A dest(obj);
    dest = obj;
    return 0;
}
