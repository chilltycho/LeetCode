//给定含n个正整数的数组和正整数s，找出数组中满足其和>=s的长度最小的连续子数组，返回其长度。若不存在，返回0
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
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
//返回大于等于target的下标
int lowerBound(vector<int> &a, int l, int r, int target)
{
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }
    return a[l] >= target ? l : -1;
}
//确定每个子数组开始下标后，使用二分查找。O(nlogn)
int minSubArrayLen_1(int s, vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int len = nums.size();
    int minLen = len + 1;
    vector<int> sums(len + 1, 0);
    for (int i = 1; i <= len; i++)
        sums[i] = sums[i - 1] + nums[i - 1];
    for (int i = 1; i <= len; i++)
    {
        int target = s + sums[i - 1];
        int bound = lowerBound(sums, i, len, target);
        if (bound != -1)
            minLen = min(minLen, bound - i + 1);
    }
    return minLen == len + 1 ? 0 : minLen;
}

int minSubArrayLen_bru(int s, vector<int> &nums)
{
    int len = nums.size();
    if (len == 0)
        return 0;
    int ans = INT32_MAX;
    for (int i = 0; i < len; i++)
    {
        int sum = 0;
        for (int j = i; j < len; j++)
        {
            sum += nums[j];
            if (sum >= s)
            {
                ans = min(ans, j - i + 1);
                break;
            }
        }
    }
    return ans == INT32_MAX ? 0 : ans;
}

int main()
{
    vector<int> vi{2, 3, 1, 2, 4, 3};
    assert(2 == minSubArrayLen_bru(7, vi)); //[4.3]符合条件
}