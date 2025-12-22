#include <iostream>
#include <vector>
#include <ctime>       // For time()
#include <cstdlib>     // For rand(), srand()
#include <algorithm>   // For std::sort (to verify results manually)
#include "Span.hpp"

int main()
{
    std::cout << "==== TEST 1: Subject Example ====" << std::endl;
    {
        Span sp = Span(5);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
        std::cout << "Longest : " << sp.longestSpan() << " (Expected: 14)" << std::endl;
    }

    std::cout << "\n==== TEST 2: Exception Handling ====" << std::endl;
    {
        // A. Adding too many numbers
        try {
            Span sp(2);
            sp.addNumber(1);
            sp.addNumber(2);
            std::cout << "Adding 3rd number to size 2 Span..." << std::endl;
            sp.addNumber(3); // Should throw
        } catch (const std::exception& e) {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }

        // B. Calculating span with not enough numbers
        try {
            Span sp(5);
            sp.addNumber(1);
            std::cout << "Calculating span with 1 number..." << std::endl;
            std::cout << sp.shortestSpan(); // Should throw
        } catch (const std::exception& e) {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }
    }

    {
        Span bigSpan(15000);

        std::vector<int> randVec;
        srand(time(NULL));
        for (int i = 0; i < 15000; i++) {
            randVec.push_back(rand());
        }

        try {
            bigSpan.addNumber(randVec.begin(), randVec.end());
            std::cout << "Added 15,000 numbers successfully." << std::endl;
        } catch (const std::exception& e) {
             std::cerr << "Error adding range: " << e.what() << std::endl;
        }

        std::sort(randVec.begin(), randVec.end());
        int manualShortest = randVec[1] - randVec[0];
        for (size_t i = 1; i < randVec.size(); i++) {
            if (randVec[i] - randVec[i - 1] < manualShortest)
                manualShortest = randVec[i] - randVec[i - 1];
        }
        int manualLongest = randVec.back() - randVec.front();

        std::cout << "[Check] Real Shortest: " << manualShortest << std::endl;
        std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
        
        std::cout << "[Check] Real Longest : " << manualLongest << std::endl;
        std::cout << "Longest Span : " << bigSpan.longestSpan() << std::endl;
    }

    return 0;
}