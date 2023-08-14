/*给定杨辉三角形，找出自顶向下最小路径和。
每步只能向下移动到下标相同或下标+1的节点*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// f[i][j]=min(f[i-1][j-1],f[i-1][j])+c[i][j]
int minimumTotal(vector<vector<int>> &traingle) {
  int n = traingle.size();
  vector<vector<int>> dp(n, vector<int>(n));
  dp[0][0] = traingle[0][0];
  for (int i = 1; i < n; i++) {
    // 第一列只能由上面而来
    dp[i][0] = dp[i - 1][0] + traingle[i][0];
    // 中间列选择上面或左上较大的
    for (int j = 1; j < i; j++)
      dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + traingle[i][j];
    // 最后一列只能由左上角而来
    dp[i][i] = dp[i - 1][i - 1] + traingle[i][i];
  }
  return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}

