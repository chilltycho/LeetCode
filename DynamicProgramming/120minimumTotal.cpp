/*给定杨辉三角形，找出自顶向下最小路径和。
每步只能向下移动到下标相同或下标+1的节点*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//f[i][j]=min(f[i-1][j-1],f[i-1][j])+c[i][j]
int minimumTotal(vector<vector<int>> &traingle)
{
    int n = traingle.size();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = traingle[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + traingle[i][0];
        for (int j = 1; j < i; j++)
            dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + traingle[i][j];
        dp[i][i] = dp[i - 1][i - 1] + traingle[i][i];
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}