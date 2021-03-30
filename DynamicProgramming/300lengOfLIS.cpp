#include <iostream>
#include <vector>
using namespace std;
/*
最长上升子序列问题：给定一个无序的整数数组，找到其中最长上升子序列的长度。
[10,9,2,5,3,7,101,18] 最长上升子序列是[2,3,7,101] 长度为4
注意子序列和子串的区别，子串一定是连续的，子序列不一定连续。

动态规划核心设计思想是数学归纳法。
可假设dp[0,...,i-1]已经被计算出来了，怎样通过这些结果算出dp[i]?
1.明确dp[i]意义，dp[i]表示以nums[i]这个数结尾的最长递增子序列长度。
2.若nums[i]>nums[i-1]，则dp[i]=dp[i-1]+1。否则比较dp[i-2]直到nums[i-k]>nums[i]或i-k<0为止
*/
int lengofLIS(vector<int> &nums)
{
    vector<int> dp(nums.size(), 1); //初始化为1，因为对每个元素最短上升子序列为其本身，也就是1，注意dp数组长度
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    int res = 0;
    for (int i = 0; i < dp.size(); i++)
        res = max(res, dp[i]);
    return res;
}

int main()
{
    vector<int> a{10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengofLIS(a);
}

vector<int> LIS(vector<int> &arr)
{
    // write code here
    // write code here
    // 第一步：利用贪心+二分求最长递增子序列长度
    vector<int> res;
    vector<int> maxLen;
    if (arr.size() < 1)
        return res;
    res.emplace_back(arr[0]); // 注：emplace_back(val)作用同push_back，效率更高
    maxLen.emplace_back(1);
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] > res.back())
        {
            res.emplace_back(arr[i]);
            maxLen.emplace_back(res.size());
        }
        else
        {
            // lower_bound(begin, end, val)包含在<algorithm>中
            // 它的作用是返回有序数组begin..end中第一个大于等于val的元素的迭代器
            int pos = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
            res[pos] = arr[i];
            maxLen.emplace_back(pos + 1);
        }
    }
    // 第二步：填充最长递增子序列
    for (int i = arr.size() - 1, j = res.size(); j > 0; --i)
    {
        if (maxLen[i] == j)
        {
            res[--j] = arr[i];
        }
    }
    return res;
}