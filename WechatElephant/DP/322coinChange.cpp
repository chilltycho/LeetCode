#include <cassert>
#include <vector>
using namespace std;
//给定不同面额硬币coins,总金额amount。求凑成总金额所需最少硬币数目。每种硬币无限，若凑不成，返回-1
int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    vector<unsigned> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (const auto c : coins)
        {
            if (i >= c)
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
    assert(3 == coinChange(c, a));
    vector<int> c1{2};
    auto a1 = 3;
    assert(-1 == coinChange(c1, a1));
}