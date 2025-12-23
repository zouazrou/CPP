#include <iostream>
#include <vector>

void    algo(std::vector<int>& input, int PairSize, int lvl)
{
    int NumPairs;

    // std::cout << "---------------------" << std::endl;
    lvl++;
    if (PairSize == 0)
        PairSize = 2;
    else
        PairSize *= 2;
    NumPairs = input.size()/PairSize;
    std::cout << "-->Lvl : " << lvl << " >> Number of Pairs :" << NumPairs << " >> size Pairs : " << PairSize << std::endl;
    if (NumPairs > 0)
        algo(input, PairSize, lvl);
    std::cout << "-->Lvl : " << lvl << " >> Number of Pairs :" << NumPairs << " >> size Pairs : " << PairSize << std::endl;

    
    for (int it_num = 0; it_num < NumPairs; it_num++)
    {
        
    }
    

}

int main()
// int main(int ac, char *av[])
{
    std::vector<int> input;
    int arr[] = {5, 2, 8, 0, 1, 7, 6, 9, 4, 3};
    
    for (int i = 0; i < 10; i++)
        input.push_back(arr[i]);


    std::cout << "          SIZE NUMBERS IS : " << input.size() << std::endl;
    algo(input, 0, 0);
    return 0;
}
