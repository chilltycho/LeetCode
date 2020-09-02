/*给定只包含正整数非空数组，是否可将数组分割成两个子集，使两个子集元素和相等*/
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;
//转换0-1背包问题，挑选一些数，使得和为整个数组元素和的一半(和一定为偶)。
bool canPartition(vector<int> &nums)
{
    auto len = nums.size();
    if (len == 0)
        return false;
    int sum = 0;
    for (auto num : nums)
        sum += num;
    if ((sum & 1) == 1)
        return false;
    int target = sum / 2;
    //从[0,i]挑选一些数，每个只能用一次，使得这些数和恰好等于j
    //dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i]]  需保证j>=nums[i]
    vector<vector<bool>> dp(len, vector<bool>(target + 1, false));
    if (nums[0] <= target)
        dp[0][nums[0]] = true;
    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (nums[i] > j) //装不下
                dp[i][j] = dp[i - 1][j];
            if (nums[i] == j) //刚好
            {
                dp[i][j] = true;
                continue;
            }
            if (nums[i] < j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
        }
    }
    return dp[len - 1][target];
}

//空间优化，dp[i][j]只考虑了dp[i-1][]上一行，故只需两行，事实上仅两个元素：一个为顶上元素，一个为左上角元素
bool canPartition_sp(vector<int> &nums)
{
    if (nums.empty())
        return false;
    auto len = nums.size();
    int sum = 0;
    for (auto num : nums)
        sum += num;
    if ((sum & 1) == 1)
        return false;
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int i = 1; i < len; i++)
    {
        for (int j = target; nums[i] <= j; j--) //0-1背包问题，故逆序
        {
            if (dp[target])
                return true;
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp[target];
}
int main()
{
    vector<int> v1{1, 5, 11, 5};
    assert(canPartition_sp(v1));
    vector<int> v2{1, 2, 3, 5};
    assert(!canPartition_sp(v2));
}