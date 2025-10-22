#include <cmath>
#include <iostream>

using namespace std;

class fixed
{
private:
    /* data */
public:
    fixed(/* args */);
    ~fixed();
};

fixed::fixed()
{
}

fixed::~fixed()
{
}

int main(int argc, char const *argv[])
{
    float nb = 10859.008;
    cout << round(nb) << endl;     
    return 0;
}
