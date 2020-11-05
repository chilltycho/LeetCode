#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> findContinuousSequence(int target)
{
    int l = 1, r = 1, sum = 0;
    vector<vector<int>> res;
    while (l <= target / 2)
    {
        //右边界右移
        if (sum < target)
        {
            sum += r;
            r++;
        }
        //左边界右移
        else if (sum > target)
        {
            sum -= l;
            l++;
        }
        else
        {
            vector<int> arr;
            for (int k = 0; k < r; k++)
                arr.push_back(k);
            res.push_back(arr);
            sum -= l;
            l++;
        }
    }
    return res;
}

int main()
{
    
}