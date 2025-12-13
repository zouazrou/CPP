#include <iostream>
#include "Array.hpp"

int main(void)
{

    {
        Array<int> arr(5);
        std::cout << "Size of arr: " << arr.size() << std::endl;
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
        for (unsigned int i = 0; i < arr.size(); i++)
            arr[i] = i * 10;
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
        std::cout << "------------" << std::endl;
        try
        {
            arr[5] = 100;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        Array<std::string> arr(3);
        std::cout << "Size of arr: " << arr.size() << std::endl;
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
        arr[0] = "W";
        arr[1] = "Fin";
        arr[2] = "!";
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << "arr[" << i << "] = " <<  arr[i] << std::endl;
        std::cout << "------------" << std::endl;
        try
        {
            arr[3] = "Out of range";
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        Array<double> emptyArr;
        std::cout << "Size of arr: " << emptyArr.size() << std::endl;
        std::cout << "Size of emptyArr: " << emptyArr.size() << std::endl;
        try
        {
            emptyArr[0] = 3.14;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        const Array<char> charArr(4);
        std::cout << "Size of charArr: " << charArr.size() << std::endl;
        try
        {
            std::cout << "charArr[0]: " << static_cast<int>(charArr[0]) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}
