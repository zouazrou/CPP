#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
    Animal *arr[4];
    
    std::cout << std::endl << "------new-Dogs-------" << std::endl;
    for (int i = 0; i < 2; i++)
        arr[i] = new Dog;
    
    std::cout << std::endl << "------new-Cats-------" << std::endl;
    for (int i = 2; i < 4; i++)
        arr[i] = new Cat;
    
    std::cout << std::endl << "------Deep-Copy-Dog-------" << std::endl;
    Dog srcDog;
    Dog destDog(srcDog);

    std::cout << std::endl << "------Deep-Copy-Cat-------" << std::endl;
    Cat srcCat;
    Cat destCat(srcCat);
    
    std::cout << std::endl << "------Delete-------" << std::endl;
    for (int i = 0; i < 4; i++)
        delete arr[i];
    return (0);
}