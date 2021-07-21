/*
n个骰子扔在地上，所有骰子朝上一面的点数之和为s，输入n，打印s所有可能的值出现的概率
输入：1
输出：[0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
输入：2
输出：[0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
*/
#include <vector>
#include <cmath>
using namespace std;
/* 动态规划：假设前n-1个解f(n-1)，添加一个骰子，求n个骰子点数和为x概率f(n,x)
f(n,x)=sum[i=1..6]f(n-1,x-i)*1/6*/
vector<double> dicesProbability(int n)
{
    vector<double> dp(6, 1.0 / 6.0);
    for (int i = 2; i <= n; i++)
    {
        vector<double> tmp(5 * i + 1, 0);
        for (int j = 0; j < dp.size(); j++)
        {
            for (int k = 0; k < 6; k++)
                tmp[j + k] += dp[j] / 6.0;
        }
        dp = tmp;
    }
    return dp;
}

vector<double> sol(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));
    for (int i = 1; i <= 6; ++i)
        dp[1][i] = 1; // 可能出现次数
    for (int i = 2; i <= n; ++i) // 骰子数量
    {
        for (int j = i; j <= 6 * i; ++j) // 可能的点数
        {
            for (int k = 1; k <= 6; ++k) 
            {
                if (j - k > 0)
                    dp[i][j] += dp[i - 1][j - k]; // i个骰子能投点数次数和i-1个骰子间关系
                else
                    break;
            }
        }
    }
    vector<double> res(n * 6 - n + 1);
    double denom = pow(6.0, n);
    for (int i = n; i <= 6 * n; ++i)
        res[i - n] = dp[n][i] / denom;
    return res;
}