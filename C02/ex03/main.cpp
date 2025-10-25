#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
    Point const A(0.0f, 0.0f);
    Point const B(20.0f, 0.0f);
    Point const C(10.0f, 20.0f);
    std::cout << std::boolalpha;
    std::cout << "--- Inside Points (Should be 1) ---" << std::endl;
    {
        Point p(10, 5);
        std::cout << bsp(A, B, C, p) << std::endl; // Expected: 1
    }
    {
        Point p(5, 2);
        std::cout << bsp(A, B, C, p) << std::endl; // Expected: 1
    }
    {
        Point p(15, 2);
        std::cout << bsp(A, B, C, p) << std::endl; // Expected: 1
    }
    {
        // Close to C
        Point p(10, 19.9f);
        std::cout << bsp(A, B, C, p) << std::endl; // Expected: 1
    }

    // --- Points OUTSIDE ---
    std::cout << "\n--- Outside Points (Should be 0) ---" << std::endl;
    {
        Point p(10, 25);
        std::cout << bsp(A, B, C, p) << std::endl; // Expected: 0
    }
    {
        Point p(10, -5);
        std::cout << bsp(A, B, C, p) << std::endl; // Expected: 0
    }
    {
        Point p(-5, 5);
        std::cout << bsp(A, B, C, p) << std::endl; // Expected: 0
    }
    {
        Point p(25, 5);
        std::cout << bsp(A, B, C, p) << std::endl; // Expected: 0
    }

    std::cout << "\n--- Boundary Points (Should be 0) ---" << std::endl;
    {
        // Vertex A
        Point p(0, 0);
        std::cout << bsp(A, B, C, p) << std::endl; // Expected: 0
    }
    {
        // Vertex B
        Point p(20, 0);
        std::cout << bsp(A, B, C, p) << std::endl; // Expected: 0
    }
    {
        // Vertex C
        Point p(10, 20);
        std::cout << bsp(A, B, C, p) << std::endl; // Expected: 0
    }
    {
        // Edge A-B
        Point p(10, 0);
        std::cout << bsp(A, B, C, p) << std::endl; // Expected: 0
    }
    {
        // Edge A-C
        Point p(5, 10);
        std::cout << bsp(A, B, C, p) << std::endl; // Expected: 0
    }
    {
        // Edge B-C
        Point p(15, 10);
        std::cout << bsp(A, B, C, p) << std::endl; // Expected: 0
    }
    return 0;
}