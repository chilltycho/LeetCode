#include <vector>
#include <iostream>
using namespace std;
//给定数组，第i个元素为第i天价格，计算能获得最大利润。最多两笔交易
int maxProfit(vector<int> &prices)
{
    if (prices.empty())
        return 0;
    const int n = prices.size();
    vector<int> s1(n + 1), s2(n + 1), s3(n + 1), s4(n + 1);
    s1[0] = INT_MIN; //持有状态，由于购买可导致负资产
    s2[0] = 0;       //未持有状态，有效值不应低于0（不买不卖）
    s3[0] = INT_MIN;
    s4[0] = 0;
    for (int k = 1; k <= n; k++)
    {
        s1[k] = max(s1[k - 1], -prices[k - 1]);
        s2[k] = max(s2[k - 1], s1[k - 1] + prices[k - 1]);
        s3[k] = max(s3[k - 1], s2[k - 1] - prices[k - 1]);
        s4[k] = max(s4[k - 1], s3[k - 1] + prices[k - 1]);
    }
    return max(0, max(s2[n], s4[n]));
}

int maxProfit_1(vector<int> &prices)
{
    int n = prices.size();
    int max_k = 2;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(max_k + 1, vector<int>(2)));
    for (int i = 0; i < n; i++)
    {
        for (int k = max_k; k >= 1; k--)
        {
            if (i - 1 == -1)
            {
                dp[i][k][0] = 0;
                dp[i][k][1] = -prices[i];
                continue;
            }
            dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
            dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
        }
    }
    return dp[n - 1][max_k][0];
}

int main()
{
    vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit_1(prices) << endl; //应为6
    vector<int> prices1{1, 2, 3, 4, 5};
    cout << maxProfit_1(prices1) << endl; //应为4
}