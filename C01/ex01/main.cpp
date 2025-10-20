#include "Zombie.hpp"

int main(void)
{
    int N = -1;
    Zombie *arr = Zombie::zombieHorde(N, "x");
    for (int i = 0; i < N; i++)
    {
        arr[i].announce();
    }
    delete[] arr;

    return 0;
}
