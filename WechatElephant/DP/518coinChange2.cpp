#include <vector>
#include <cassert>
#include <iostream>

using namespace std;
//给定不同面额的硬币和一个总金额。计算可凑成总金额硬币组合数，每种硬币无限。方案不能重复
int change(int amount, vector<int> &coins)
{
    if (amount == 0)
        return 1;
    if (coins.empty())
        return 0;
    const auto m = coins.size();
    vector<vector<int>> dp(m + 1, vector<int>(amount + 1));
    for (int i = 0; i <= m; i++)
    {
        for (int k = 0; k <= amount; k++)
        {
            if (k == 0)
                dp[i][k] = 1;
            else if (i == 0)
                dp[i][k] = 0;
            else
            {
                dp[i][k] = dp[i - 1][k];
                if (k >= coins[i - 1])
                    dp[i][k] += dp[i][k - coins[i - 1]];
            }
        }
    }
    return dp[m][amount];
}

int main()
{
    int amount = 5;
    vector<int> coins{1, 2, 5};
    cout << change(amount, coins) << endl;
}