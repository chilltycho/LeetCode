/*给定表示分数的非负整数数组，玩家1从任一端取一个，再玩家2取。...最终获得分数总和最多玩家获胜。
预测玩家1是否会成为玩家，假设每个玩家会使分数最大化*/
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int helper(vector<int> &nums, int i, int j) //i,j表示区间
{
    if (i == j) //仅一个数
        return nums[i];
    auto pickI = nums[i] - helper(nums, i + 1, j);//玩家1-玩家2，最后若>=0则获胜
    auto pickJ = nums[j] - helper(nums, i, j - 1);
    return max(pickI, pickJ);//返回赢过对方分数
}

bool PredictTheWinner_re(vector<int> &nums)
{
    return helper(nums, 0, nums.size() - 1) >= 0;
}

bool PredictTheWinner_dp(vector<int>& nums)
{
    if(nums.empty())
        return true;
    auto size=nums.size();
    vector<vector<int>> dp(size,vector<int>(size));
    for(int i=0;i<size;i++)
    {
        dp[i][i]=nums[i];
    }

    for(int i=size-2;i>=0;i--)
    {
        for(int j=i+1;j<size;j++)
        {
            auto pickI=nums[i]-dp[i+1][j];
            auto pickJ=nums[j]-dp[i][j-1];
            dp[i][j]=max(pickI,pickJ);
        }
    }
    return dp[0][size-1]>=0;
}

int main()
{
    vector<int> v1{1, 5, 2};
    assert(false == PredictTheWinner_dp(v1));
    vector<int> v2{1, 5, 233, 7};
    assert(true == PredictTheWinner_dp(v2));
}