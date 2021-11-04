#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
//不能偷相邻，首尾相邻。分为偷第一间，偷最后一间
int ite(vector<int> &nums, int start, int end)
{
    auto size = end - start;
    vector<int> dp(size + 1, 0);
    dp[1] = nums[start];
    for (auto i = 2; i <= size; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i - 1]);
    }
    return dp[size];
}

int ite_1(vector<int> &nums, int start, int end)
{
    auto size = end - start;
    int pre = 0, cur = nums[start], temp = 0;
    for (int i = 2; i <= size; i++)
    {
        temp = cur;
        cur = max(cur, pre + nums[start + i - 1]);
        pre = temp;
    }
    return cur;
}

int rob(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    return max(ite(nums, 0, nums.size() - 1), ite(nums, 1, nums.size()));
}

int main()
{
    vector<int> vi{2, 3, 2};
    assert(3 == rob(vi));
    vector<int> vi1{1, 2, 3, 1};
    assert(4 == rob(vi1));
}