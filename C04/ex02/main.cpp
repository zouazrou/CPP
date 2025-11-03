#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define NUM_ANIMAL  4

int main() {
    const Animal* animals[NUM_ANIMAL];

    // Create half Dog and half Cat objects
    std::cout << std::endl << "==========NEW-DOG==========" << std::endl;
    for (int i = 0; i < NUM_ANIMAL / 2; ++i) {
        animals[i] = new Dog();
    }
    std::cout << std::endl << "==========NEW-CAT==========" << std::endl;
    for (int i = NUM_ANIMAL / 2; i < NUM_ANIMAL; ++i) {
        animals[i] = new Cat();
    }

    std::cout << std::endl << "==========MakeSound==========" << std::endl;

    // Call makeSound for each Animal
    for (int i = 0; i < NUM_ANIMAL; ++i) {
        animals[i]->makeSound();
    }

    std::cout << std::endl << "==========DELETE==========" << std::endl;

    // Delete all Animals
    for (int i = 0; i < NUM_ANIMAL; ++i) {
        delete animals[i];
    }

    std::cout << std::endl << "==========DEEP-COPY-DOG==========" << std::endl;

    // Test deep copy
    Dog dog1;
    Dog dog2 = dog1; // Copy constructor
    Dog dog3;
    dog3 = dog1; // Copy assignment operator

    std::cout << std::endl << "==========DEEP-COPY-CAT==========" << std::endl;
    Cat cat1;
    Cat cat2 = cat1; // Copy constructor
    Cat cat3;
    cat3 = cat1; // Copy assignment operator

    std::cout << std::endl << "==========DESTRUCTOR==========" << std::endl;

    return 0;
}