//每次交易需手续费，可无限次
#include <vector>
#include <iostream>
using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
    if (prices.empty())
        return 0;
    int n = prices.size();
    int dp[n][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0] - fee;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
    }
    return dp[n - 1][0];
}

int maxProfit(vector<int> &prices, int fee)
{
    if (prices.empty())
        return 0;
    int n = prices.size();
    int dp0 = 0;
    int dp1 = -prices[0] - fee;
    for (int i = 1; i < n; i++)
    {
        int temp = dp0;
        dp0 = max(dp0, dp1 + prices[i]);
        dp1 = max(dp1, temp - prices[i] - fee);
    }
    return dp0;
}