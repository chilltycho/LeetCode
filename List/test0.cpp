#include <iostream>
#include <vector>
using namespace std;

// 滑动窗口法
int sol(vector<int> &nums, int k)
{
    int l = 0, r = 0;
    int cursum = nums[0];
    int res = 0;
    while (r < nums.size())
    {
        if (cursum == k) // 找到符合条件窗口，窗口和==k
        {
            res = max(res, r - l + 1); // 更新最长长度
            cursum -= nums[l++];       // 窗口右移，后面可能有更好的解
        }
        else if (cursum < k)    // 窗口之和<k
        
        {
            r++;       // 扩张窗口右边界
            if (r == nums.size()) // 到达数组边界，直接退出
                break;
            cursum += nums[r];  // 否则向右扩张窗口
        }
        else
            cursum -= nums[l++]; // 窗口之和过大，窗口左边界右移。
    }
    return res;
}

int main()
{
    vector<int> vi{1, 3, 1, 1, 1, 2};
    int k = 4;
    cout << sol(vi, k) << endl; // 4
}