#include <iostream>
#include <cassert>
#include <vector>
#include <climits>
using namespace std;
//股票最多交易一次
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int dp[n][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], -prices[i]);
    }
    return dp[n - 1][0];
}
//第i天收益只和第i-1天的最大收益相关。
int maxProfit_1(vector<int> &prices)
{
    int n = prices.size();
    int dp0 = 0;
    int dp1 = -prices[0];
    for (int i = 1; i < n; i++)
    {
        dp0 = max(dp0, dp1 + prices[i - 1]);
        dp1 = max(dp1, -prices[i - 1]);
    }
    return dp0;
}

int main()
{
    vector<int> v1{7, 1, 5, 3, 6, 4}; //第2天(1)买入，第5天(6)卖出。利润为5
    assert(5 == maxProfit_1(v1));
    vector<int> v2{7, 6, 5, 3, 1}; //不买入，利润为0
    assert(0 == maxProfit_1(v2));
}