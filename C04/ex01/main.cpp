#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << "=====================" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << "=====================" << std::endl;
    delete meta;
    delete j;
    delete i;
    
    std::cout << "=====================" << std::endl;
    const WrongAnimal *deta = new WrongAnimal();
    const Animal *correctDog = new Dog();
    const WrongAnimal *wrongCat = new WrongCat();
    std::cout << "=====================" << std::endl;
    std::cout << correctDog->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    correctDog->makeSound();
    deta->makeSound();
    std::cout << "=====================" << std::endl;
    delete deta;
    delete correctDog;
    delete wrongCat;
    return 0;
}