#include <vector>
#include <cassert>
using namespace std;
//给定由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数，顺序不同视为不同组合(与518不同)

/*
最后一个数选择nums[0]，方案数为f[len-1][target-nums[0]]
最后一个数选择nums[1]，方案数为f[len-1][target-nums[1]]
f[len][target]=sum(f[len-1][targe-nums[i]])
*/
int combinationSum4_1(vector<int> &nums, int target)
{
    using ull = unsigned long long;
    vector<vector<ull>> dp(target + 1, vector<ull>(target + 1, 0)); // 解长度，和
    dp[0][0] = 1;
    int res = 0;
    for (int i = 1; i <= target; ++i)
    {
        for (int j = 0; j <= target; ++j)
            for (auto c : nums)
                if (j >= c)
                    dp[i][j] += dp[i - 1][j - c];
        res += dp[i][target];
    }
    return res;
}

int combinationSum4(vector<int> &nums, int target)
{
    if (target == 0)
        return 1;
    vector<unsigned> dp(target + 1, 0); // 凑成总和方案数
    dp[0] = 1;
    for (int i = 1; i <= target; i++) // 计算任意总和时，保证每个数能考虑。
    {
        for (auto c : nums)
        {
            if (i >= c)
                dp[i] += dp[i - c];
        }
    }
    return dp[target];
}

int main()
{
    vector<int> nums{3, 2, 1};
    int target = 4;
    assert(7 == combinationSum4(nums, 4));
}