//给定不同面额的硬币和一个总金额。计算可凑成总金额硬币组合数，每种硬币无限。方案不能重复
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;
int change(int amount, vector<int> &coins)
{
    if (amount == 0)
        return 1;
    if (coins.empty())
        return 0;
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= coins.size(); ++i)
    {
        for (int j = 0; j <= amount; ++j)
        {
            if (j == 0)
                dp[i][j] = 1;
            else
            {
                if (j >= coins[i - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]]; // 完全背包，选了i后
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[coins.size()][amount];
}

int change_sp(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (auto c : coins)
    {
        for (auto x = c; x <= amount; x++)
            dp[x] += dp[x - c];
    }
    return dp[amount];
}

int main()
{
    int amount = 5;
    vector<int> coins{1, 2, 5};
    cout << change_1(amount, coins) << endl;
}
