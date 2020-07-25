#include <iostream>
#include <vector>
using namespace std;
//以斐波那契数列为例
int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}
/*画递归树为二叉树，二叉树节点总数为指数级别，所有子问题个数O(2^n)。
存在大量重复计算，如f(18)被计算两次，称为重叠子问题
*/

//带备忘录，不存在冗余计算，子问题为f(1),f(2)...。O(n)
int fib_ite(int *memo, int n)
{
    if (n == 1 || n == 2)
        return 1;
    if (memo[n] != 0)
        return memo[n];
    memo[n] = fib_ite(memo, n - 1) + fib_ite(memo, n - 2);
    return memo[n];
}
int fib_memo(int n)
{
    if (n < 1)
        return 0;
    int memo[n + 1]{0};
    return fib_ite(memo, n);
}

int fib_3(int n) //自底向上
{
    int dp[n + 1]{0};
    dp[1] = dp[2] = 1; //base case,dp[0]未使用
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
/*
状态转移f(n)=f(n-1)+f(n-2) n>2  f(n)=1  n=1,2
*/
//由于只有两个状态，故只需存储两个状态，可进一步优化空间
int fib_final(int n)
{
    if (n == 2 || n == 1)
        return 1;
    int prev = 1, curr = 1;
    for (int i = 3; i <= n; i++)
    {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    }
    return curr;
}

//最优子结构，设计求最值。
/*凑零钱问题：给k种面值硬币，面值为c1,c2,...,ck,每种硬币数量无线，给定总额amount
问最少需几枚硬币凑出这个金额，若不可能凑出，返回-1*/
//子问题相互独立，如amount=11，已知amount=10凑法（子问题）再加1即可（硬币数量无限，子问题间没相互制约

/*解答：
1.确定状态：原问题和子问题中变化的量。为amount
2.确定dp函数：当前目标金额为n，至少需dp(n)凑出金额
3.确定并选择最优：对每个状态，可做什么选择改变当前状态。当前为选择一个硬币
*/
int coinChange(const vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    if (amount < 0)
        return -1; //base case
    int res = INT_MIN;
    for (auto coin : coins)
    {
        res = min(res, 1 + coinChange(coins, amount - coin));
    }
    return res;
}

int coinChange_ite(const vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        for (int coin : coins)
        {
            if (i - coin < 0)
                continue;
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}


