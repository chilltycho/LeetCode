//给定不同面额硬币coins,总金额amount。求凑成总金额所需最少硬币数目。每种硬币无限，若凑不成，返回-1
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;
int coinChange_1(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, amount + 2));
    dp[0][0] = 0;
    for (int i = 1; i <= coins.size(); ++i)
    {
        for (int j = 0; j <= amount; ++j)
        {
            if (j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (j >= coins[i - 1])
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[coins.size()][amount] == amount + 2 ? -1 : dp[coins.size()][amount];
}
int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    vector<unsigned> dp(amount + 1, amount + 1); //假设都凑不出来
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) //dp[amount]=min(1+dp[amount-coins[i]])
    {
        for (const auto c : coins)
        {
            if (i >= c && dp[i - c] != amount + 1)
                dp[i] = min(dp[i], 1 + dp[i - c]);
        }
    }
    if (dp[amount] > amount)
        return -1;
    else
        return dp[amount];
}

int main()
{
    vector<int> c{1, 2, 5};
    auto a = 11;
    cout << coinChange_1(c, a) << endl;
    //assert(3 == coinChange_1(c, a));
    vector<int> c1{2};
    auto a1 = 3;
    //assert(-1 == coinChange_1(c1, a1));
}