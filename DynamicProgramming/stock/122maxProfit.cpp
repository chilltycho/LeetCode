#include <iostream>
#include <vector>
#include <cassert>
#include <climits>
using namespace std;
//可多次交易
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int dp[n + 1][2];
    dp[0][0] = 0;
    dp[0][1] = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int temp = dp[i - 1][0];
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
        dp[i][1] = max(dp[i - 1][1], temp - prices[i - 1]);
    }
    return dp[n][0];
}

int main()
{
    vector<int> v1{7, 1, 5, 3, 6, 4};
    assert(7 == maxProfit(v1));
    vector<int> v2{1, 2, 3, 4, 5};
    assert(4 == maxProfit(v2));
}