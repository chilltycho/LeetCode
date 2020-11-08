#include <iostream>
#include <vector>
#include <cassert>
#include <climits>
using namespace std;
//可多次交易
int maxProfit(vector<int> &prices)
{
    if (prices.empty())
        return 0;
    int n = prices.size();
    int dp[n][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[n - 1][0];
}

int maxProfit_1(vector<int>& prices)
{
    if(prices.empty())
        return 0;
    size_t n=prices.size();
    int dp1=-prices[0],dp0=0,temp=0;
    for(int i=1;i<n;i++)
    {
        temp=dp0;
        dp0=max(dp0,dp1+prices[i]);
        dp1=max(dp1,temp-prices[i]);
    }
    return dp0;
}

int main()
{
    vector<int> v1{7, 1, 5, 3, 6, 4};
    assert(7 == maxProfit(v1));
    vector<int> v2{1, 2, 3, 4, 5};
    assert(4 == maxProfit(v2));
}