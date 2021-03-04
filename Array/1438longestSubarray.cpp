/**
 * 给定整数nums和表示限制的整数limit，返回最长连续子数组长度，子数组任意两个元素
 * 绝对差小于或等于limit
*/
#include <vector>
#include <iostream>
#include <set>
#include <deque>
using namespace std;
//O(nlogn), 用multiset统计当前窗口最大最小值
int longestSubarray(vector<int> &nums, int limit)
{
    multiset<int> s;
    int len = nums.size();
    int l = 0, r = 0;
    int res = 0;
    while (r < len)
    {
        s.insert(nums[r]);
        while (*s.rbegin() - *s.begin() > limit)
            s.erase(s.find(nums[l++]));
        res = max(res, r - l + 1);
        r++;
    }
    return res;
}

// 用两个单调队列
int longestSubarray_1(vector<int> &nums, int limit)
{
    deque<int> queMax, queMin;
    int len = nums.size();
    int l = 0, r = 0;
    int res = 0;
    while (r < len)
    {
        while (!queMax.empty() && queMax.back() < nums[r])
            queMax.pop_back();
        while (!queMin.empty() && queMin.back() > nums[r])
            queMin.pop_back();
        queMax.push_back(nums[r]);
        queMin.push_back(nums[r]);
        while (!queMax.empty() && !queMin.empty() && queMax.front() - queMin.front() > limit)
        {
            if (nums[l] == queMin.front())
                queMin.pop_front();
            if (nums[l] == queMax.front())
                queMax.pop_front();
            l++;
        }
        res = max(res, r - l + 1);
        r++;
    }
    return res;
}

int main()
{
    vector<int> nums{8, 2, 4, 7};
    cout << longestSubarray(nums, 4) << endl; //2
}
