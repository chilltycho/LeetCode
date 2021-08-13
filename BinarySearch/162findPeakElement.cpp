// 寻找峰值，假设nums[-1]=nums[n]=-inf
#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (nums[m] < nums[m + 1]) // 左边小于右边，右边可能有峰值
            l = m + 1;
        else
            r = m;
    }
    return l;
}