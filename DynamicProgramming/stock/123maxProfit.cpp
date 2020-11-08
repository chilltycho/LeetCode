#include <vector>
#include <iostream>
#include<cstring>
#include <climits>
using namespace std;
//给定数组，第i个元素为第i天价格，计算能获得最大利润。最多两笔交易
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int dp[n][3][2];
    memset(dp,0,sizeof(dp));
    dp[0][1][0] = 0;
    dp[0][1][1] = -prices[0];
    dp[0][2][0] = 0;
    dp[0][2][1] = -prices[0];

    for (int i = 1; i < n; i++)
    {
        dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i]);
        dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i]);
        dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i]);
        dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][0] - prices[i]);
    }
    return dp[n - 1][2][0];
}

int main()
{
    vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices) << endl; //应为6
    vector<int> prices1{1, 2, 3, 4, 5};
    cout << maxProfit(prices1) << endl; //应为4
}