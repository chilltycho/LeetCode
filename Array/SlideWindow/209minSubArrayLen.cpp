//给定含n个正整数的数组和正整数s，找出数组中满足其和>=s的长度最小的连续子数组，返回其长度。若不存在，返回0
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

int minSubArrayLen(int s, vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int len = nums.size();
    int l = 0, r = 0;
    int sum = 0;
    int minLen = len + 1;
    while (r < len)
    {
        sum += nums[r];
        r++;
        while (sum >= s) //找到一个窗口
        {
            minLen = min(minLen, r - l);
            sum -= nums[l];
            l++;
        }
    }

    if (minLen == len + 1)
        return 0;
    return minLen;
}

int main()
{
    vector<int> vi{2, 3, 1, 2, 4, 3};
    assert(2 == minSubArrayLen(7, vi)); //[4.3]符合条件
}