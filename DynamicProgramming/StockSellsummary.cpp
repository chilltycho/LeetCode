#include <iostream>
#include <vector>
using namespace std;
/*以状态进行穷举，先看有几种状态，再找出对应的选择。
for 状态1 in 状态1所有取值：
    for 状态2 in 状态2所有取值：
        for...
            dp[状态1][状态2][...]=择优(选择1，选择2)
对股票问题，有三种选择：买入，卖出，无操作。但不是每天都能卖
dp[3][2][1]表示第3天，最多进行两次交易，持有股票
则最终答案应为dp[n-1][k][0]最后一天，最多允许k次，卖出股票

dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])

base case:
dp[-1][k][0]=0 
dp[-1][k][1]=-infinity
dp[i][0][0]=0
dp[i][0][1]=-infinity
*/
#if 0
int maxProfit_1(vector<int> &prices)
{
    int n = prices.size();
    int dp[n][n];
    for (int i = 0; i < n; i++)
    {
        if (i - 1 == -1)
        {
            dp[i][0] = 0;
            dp[i][1] = INT_MIN;
            continue;
        }
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], -prices[i]);
    }
    return dp[n - 1][0];
}

//注意dp[i]只和dp[i-1]有关
int maxProfit_1Optimize(vector<int> &prices)
{
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, -prices[i]);
    }
    return dp_i_0;
}

//122题 k无限，则k=k-1
int maxProfit_3(vector<int> &prices)
{
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int temp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, temp - prices[i]);
    }
    return dp_i_0;
}
#endif
//123 k=2
int maxProfit_2(vector<int> &prices)
{

    if (prices.empty())
        return 0;

    int n = prices.size();
    int max_k = 2;
    int dp[n][max_k + 1][2];
    ::memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
    {

        for (int k = 1; k <= max_k; ++k)
        {

            if (i == 0)
            {
                dp[0][k][0] = 0;
                dp[0][k][1] = -prices[0];
                continue;
            }

            dp[i][k][0] = std::max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
            dp[i][k][1] = std::max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
        }
    }

    return dp[n - 1][max_k][0];
}
int main()
{
    vector<int> vi{3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit_2(vi);
}