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
    const auto m = coins.size();
    vector<vector<int>> dp(m + 1, vector<int>(amount + 1));
    for (int i = 0; i <= m; i++)
    {
        for (int k = 0; k <= amount; k++)
        {
            if (k == 0)
                dp[i][k] = 1; //使用硬币列表[0,i]可凑成金额为j的组合数
            else if (i == 0)
                dp[i][k] = 0;
            else
            {
                dp[i][k] = dp[i - 1][k]; //f(i,k)=f(i,k-ci)+f(i-1,k)  决定拿面额最大硬币ci + 决定不拿ci只选(c1..ci)
                if (k >= coins[i - 1])
                    dp[i][k] += dp[i][k - coins[i - 1]];
            }
        }
    }
    return dp[m][amount];
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
