#include "Zombie.hpp"

int main(void)
{
    
    Zombie zmb("Z");
    zmb.announce(); 
    Zombie *ptr = Zombie::newZombie("X");
    ptr->announce();
    delete ptr;
    Zombie::randomChump("Y");
    return 0;
}
