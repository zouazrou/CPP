#include <iostream>
#include <vector>
// #include <ford_johnson_algrithm>
#include <cmath>

size_t jacobsthal(size_t n)
{
    // if (n == 0) return 0;
    // if (n == 1) return 1;
    // return (jacobsthal(n-1) + 2*jacobsthal(n-2));

    return ((pow(2, n) - (pow(-1, n))) / 3);
}

void printVector(const std::vector<int> &vec)
{
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

size_t startPair(size_t idx, size_t pairSize)
{
    return (idx - pairSize + 1);
}

size_t endPair(size_t idx)
{
    return (idx + 1);
}

void ford_johnson_alg(std::vector<int> &input, int PairSize)
{
    int NumPairs;
    bool thereSinglePair;
    std::vector<int> a; // * big or winner
    std::vector<int> b; // * small or looser

    // std::cout << "---------------------" << std::endl;
    NumPairs = input.size() / (PairSize * 2);
    thereSinglePair = false;
    if (input.size() % (PairSize * 2) / PairSize)
        thereSinglePair = true;
    std::cout << "\033[1;31m-->Number of Pairs :" << NumPairs << " >> UNPAIRED PAIRS : " << thereSinglePair << " >> size single Pair : " << PairSize << "\033[0m" << std::endl;
    if (NumPairs == 0)
    {
        std::cout << "Break recursive" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        return;
    }

    for (int i = 0; i < NumPairs; i++)
    {
        a.push_back((i + 1) * PairSize * 2 - 1);
        b.push_back(a[i] - PairSize);
        std::cout << "\033[1;36mb = (" << b[i] << " , a = " << a[i] << ")\033[0m" << std::endl;
    }
    if (thereSinglePair)
    {
        std::cout << a.back() + PairSize << "  last val in vec A                     ****" << std::endl;
        b.push_back(a.back() + PairSize);
    }

    std::cout << "** Tab Before Sort Pairs **" << std::endl;
    printVector(input);
    for (int i = 0; i < NumPairs; i++)
    {
        if (input[b[i]] > input[a[i]])
        {
            std::cout << "\033[1;33mDo Swap !!\033[0m" << std::endl;
            std::swap_ranges(input.begin() + startPair(b[i], PairSize), input.begin() + endPair(b[i]), input.begin() + startPair(a[i], PairSize));
        }
    }
    std::cout << "** Tab after Sort Pairs **" << std::endl;
    printVector(input);
    ford_johnson_alg(input, PairSize * 2);
    std::cout << "\033[1;31m-->Number of Pairs :" << NumPairs << " >> UNPAIRED PAIRS : " << thereSinglePair << " >> size single Pair : " << PairSize << "\033[0m" << std::endl;
    std::cout << "before split to MAIN and PEND" << std::endl;
    printVector(input);
    std::vector<int> pendV, mainV;

    mainV.insert(mainV.end(), input.begin() + startPair(b[0], PairSize), input.begin() + endPair(b[0]));
    for (size_t i = 0; i < a.size(); i++)
    {
        mainV.insert(mainV.end(), input.begin() + startPair(a[i], PairSize), input.begin() + endPair(a[i]));
    }
    for (size_t i = 1; i < b.size(); i++)
    {
        // std::cout << b.size() << " < Insert to PEND B from idx : " << startPair(b[i], PairSize) << " to idx : " << endPair(b[i]) << std::endl;
        pendV.insert(pendV.end(), input.begin() + startPair(b[i], PairSize), input.begin() + endPair(b[i]));
    }
    
    {
        std::cout << "\33[1;32m** MAIN VECTOR **\033[0m" << std::endl;
        printVector(mainV);
        std::cout << "\33[1;32m** PEND VECTOR **\033[0m" << std::endl;
        printVector(pendV);
        std::cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
    }
    // int JB = 2;
    // int prev_JB;
    // int curr_JB = jacobsthal(JB);
    // while (NumPairs--)
    // {
    //     prev_JB = curr_JB;
    //     curr_JB = std::min(pendV.size(), jacobsthal(++JB));
    //     for (int it_JB = curr_JB; it_JB > prev_JB; it_JB--)
    //     {
    //         std::cout << it_JB << ", ";
    //     }
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    // }
}
/*
 * step 1 : put B1 and rest of A*    to MAIN container respectevly
 * step 2 : put rest of B*           to PEND container
 * step 3 :
 *
 * MAIN : B1, A1, A2
 * PEND : B2, B3 ...
 */
int main()
{
    std::vector<int> input;
    int arr[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};

    for (int i = 0; i < 22; i++)
        input.push_back(arr[i]);

    std::cout << "          SIZE NUMBERS IS : " << input.size() << std::endl;
    ford_johnson_alg(input, 1);
    return 0;
}
