#include <iostream>
#include <vector>
#include <algorithm>

void printVector(const std::vector<int>& vec)
{
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

void    algo(std::vector<int>& input, int PairSize, int lvl)
{
    int NumPairs;
    // int tmp;
    std::vector<int> a; // * big
    std::vector<int> b; // * small

    // std::cout << "---------------------" << std::endl;
    lvl++;
    if (PairSize == 0)
        PairSize = 2;
    else
        PairSize *= 2;
    NumPairs = input.size()/PairSize;
    std::cout << "\033[1;31m-->Lvl : " << lvl << " >> Number of Pairs :" << NumPairs << " >> size Pairs : " << PairSize << "\033[0m" << std::endl;
    if (NumPairs == 0)
    {
        std::cout << "Break recursive" << std::endl;
        return ;
    }

    int SecondCompared;
    int FirstCompared;
    for (int i = 0; i < NumPairs; i++)
    {
        SecondCompared = PairSize * (i+1) - 1;
        FirstCompared = SecondCompared - PairSize / 2;
        a.push_back(SecondCompared);
        b.push_back(FirstCompared);
    }
    std::cout << "** Tab Before Sort Pairs **" <<std::endl;    
    printVector(input);
    for (int i = 0; i < NumPairs; i++)
    {
        std::cout << "\033[1;32mcmp(" << input[b[i]] << " ? " << input[a[i]] << ")\033[0m" << std::endl;
        if (input[b[i]] > input[a[i]])
        {
            std::cout << "\033[1;33mDo Swap !!\033[0m" <<std::endl;
            // std::swap_ranges(input.begin()+b[i]+1, input.begin()+a[i]+1, input.begin()+b[i]-PairSize/2+1);
            std::swap_ranges(input.begin()+a[i]-PairSize/2+1, input.begin()+a[i]+1, input.begin()+b[i]-PairSize/2+1);
        }
    }
    std::cout << "** Tab after Sort Pairs **" <<std::endl;
    printVector(input);
    algo(input, PairSize, lvl);
}

int main()
{
    std::vector<int> input;
    int arr[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    
    for (int i = 0; i < 22; i++)
        input.push_back(arr[i]);


    std::cout << "          SIZE NUMBERS IS : " << input.size() << std::endl;
    algo(input, 0, 0);
    return 0;
}
