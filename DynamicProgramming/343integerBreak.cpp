//给定一个正整数n，将其拆分为至少两个正整数的和，并使这些整数乘积最大化，返回可获得的最大乘积
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
/*dp[i]最大乘积:
将i拆分为j和i-j的和，且i-j不再拆分。则为j*(i-j)
将i拆分为j和i-j的和，继续拆分i-j。则为j*dp[i-j]
dp[i]=max((i-j)*j,dp[i-j]*j)*/
int integerBreak(int n)
{
    if (n == 1)
        return 1;
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        auto temp = 0;
        for (int j = 1; j < i; j++)
            temp = max(temp, max(j * (i - j), j * dp[i - j]));
        dp[i] = temp;
    }
    return dp[n];
}

int main()
{
    assert(1 == integerBreak(2));
    assert(36 == integerBreak(10));
}