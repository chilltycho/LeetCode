//给定无序数组，找出数组在排序后，相邻元素之间最大差值，若元素个数小于2,返回0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//基数排序，先个位再十位再百位
int maximumGap(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return 0;
    int exp = 1;
    vector<int> buf(n);
    int maxVal = *max_element(nums.begin(), nums.end());
    while (maxVal >= exp)
    {
        vector<int> cnt(10);
        for (int i = 0; i < n; i++)
        {
            int digit = (nums[i] / exp) % 10;
            cnt[digit]++;
        }
        for (int i = 1; i < 10; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            int digit = (nums[i] / exp) % 10;
            buf[cnt[digit] - 1] = nums[i];
            cnt[digit]--;
        }
        copy(buf.begin(), buf.end(), nums.begin());
        exp *= 10;
    }
    int ret = 0;
    for (int i = 1; i < n; i++)
        ret = max(ret, nums[i] - nums[i - 1]);
    return ret;
}
