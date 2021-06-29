/*给定非负整数数组，a1,a2,...,an和一个目标数，有两个符号+,-。对数组中任意一个整数
可从+或-中选择一个符号添加在前面。返回可使最终数组和为目标数S的所有添加符号的方法数*/
#include <vector>
#include <cassert>
#include<numeric>
#include <cmath>
using namespace std;
int count = 0;
void calcu(vector<int> &nums, int i, int sum, int S) //dfs递归
{
    if (i == nums.size()) //树深度
    {
        if (sum == S)
            count++;
    }
    else
    {
        calcu(nums, i + 1, sum + nums[i], S);
        calcu(nums, i + 1, sum - nums[i], S);
    }
}
int findTargetSumWays_vilo(vector<int> &nums, int S)
{
    calcu(nums, 0, 0, S);
    return count;
}
int findTargetSumWays_dp(vector<int> &nums, int S)
{
    int sum = accumulate(nums.begin(),nums.end(),0);
    if (abs(S) > sum)
        return 0; //注意是非负整数数组
    auto len = nums.size();
    int t = sum * 2 + 1;                            //-sum..0..sum的dp数组
    vector<vector<int>> dp(len, vector<int>(t, 0)); //dp[i][j]:0-i个元素加减后得到j的方法数
    if (nums[0] == 0)
        dp[0][sum] = 2; //+0 -0均可，方法数为2
    else
    {
        dp[0][sum + nums[0]] = 1;
        dp[0][sum - nums[0]] = 1;
    }
    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j < t; j++)
        {
            int l = (j - nums[i]) >= 0 ? j - nums[i] : 0;
            int r = (j + nums[i]) < t ? j + nums[i] : 0;
            dp[i][j] = dp[i - 1][l] + dp[i - 1][r];
        }
    }
    return dp[len - 1][sum + S];
}
// 假定所有符号为+的数之和为x，为-的数之和为y。想要的S=x-y, 而x+y=sum。x=(S+sum)/2, 即选出几个数，另其和为target。
int findTargetSumWays_dp1(vector<int> &nums, int S)
{
    int sum = accumulate(nums.begin(),nums.end(),0);
    if (abs(S) > sum)
        return 0;
    if ((sum + S) % 2 == 1) //背包容量x应为整数
        return 0;
    auto len = (sum + S) / 2; //目标容量
    vector<int> dp(len + 1, 0);
    dp[0] = 1;
    for (auto num : nums)
    {
        for (int i = len; i >= num; --i)
            dp[i] += dp[i - num];
    }
    return dp[len];
}

int findTargetSumWays_dp2(vector<int> &nums, int S)
{
    int sum = accumulate(nums.begin(),nums.end(),0);
    if (abs(S) > sum)
        return 0;
    if ((sum + S) % 2 == 1) //背包容量x应为整数
        return 0;
    auto len = (sum + S) / 2; //目标容量
    vector<vector<int>> dp(nums.size() + 1, vector<int>(len + 1, 0));
    dp[0][0] = 1;
    dp[0][nums[0]] = 1;
    for (int i = 1; i <= nums.size(); i++)
    {
        for (int j = 0; j <= len; j++)
        {
            if (j >= nums[i])
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[nums.size()][len];
}

int main()
{
    vector<int> nums{1, 1, 1, 1, 1};
    int S = 3;
    assert(5 == findTargetSumWays_dp2(nums, S));
}