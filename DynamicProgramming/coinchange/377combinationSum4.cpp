#include <vector>
#include <cassert>
using namespace std;
//给定由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数，顺序不同视为不同组合(与518不同)

// 排列组合，回溯法求种类数用动态规划
int combinationSum4(vector<int> &nums, int target) 
{
    if (target == 0)
        return 1;
    vector<unsigned> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) 
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