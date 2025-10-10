#include <iostream>

using namespace std;

bool is_sorted(string num)
{
    int i = 0;
    while (++i < num.size())
    {
        if (num[i-1] < num[i])
            return (false);
    }
    return (true);
}

int maximumSwap(int num) {
    string numstr = to_string(num);
    if (is_sorted(numstr) == true)
        return (num);

    int idx_l;
    int idx_r = -1;
    for (int i = 0; i < numstr.size(); i++)
    {
        idx_l = i;
        for (int j = i+1; j < numstr.size(); j++)
        {
            if (idx_r == -1 && numstr[idx_l] < numstr[j])
            {
                idx_r = j; 
                break;
            }
        }
        if (idx_r != -1)
            break;
    }
    if (idx_r != -1)
    {
        for (int i = idx_r + 1; i < numstr.size(); i++)
        {
            if (numstr[idx_r] <= numstr[i])
                idx_r = i;
        }
        swap(numstr[idx_l], numstr[idx_r]);
    }
    return  (stoi(numstr));
}

int main(int argc, char const *argv[])
{
    int num = 98368;
    cout << "Input    : " << num << endl;
    cout << "Output   : " << maximumSwap(num) << endl;
    // cout << "Expected : " << 98863 << endl;
    return 0;
}

/*
    ! case 1;
    * Input    :2 7 3 6
    ? index    :0,1,2,3
    * Expected :7 2 3 6
!  idx_l = 2
!  idx_r = 4

*/