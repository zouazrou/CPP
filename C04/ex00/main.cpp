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
    
    const WrongAnimal *deta = new WrongAnimal();
    const Animal *a = new Dog();
    const WrongAnimal *b = new WrongCat();
    std::cout << "=====================" << std::endl;
    std::cout << a->getType() << " " << std::endl;
    std::cout << b->getType() << " " << std::endl;
    b->makeSound();
    a->makeSound();
    deta->makeSound();
    std::cout << "=====================" << std::endl;
    delete deta;
    delete a;
    delete b;
    return 0;
}