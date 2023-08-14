//最多可完成k笔交易
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
//可无限次交易
int maxProfit_mul(vector<int> &prices) {
  if (prices.empty())
    return 0;
  size_t n = prices.size();
  int dp1 = -prices[0], dp0 = 0, temp = 0;
  for (int i = 1; i < n; i++) {
    temp = dp0;
    dp0 = max(dp0, dp1 + prices[i]);
    dp1 = max(dp1, temp - prices[i]);
  }
  return dp0;
}

int maxProfit(int k, vector<int> &prices) {
  if (prices.empty())
    return 0;
  int n = prices.size();
  if (k >= n / 2) //相当于可无限次交易，可不进行该特例
    return maxProfit_mul(prices);
  int dp[n][k + 1][2];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= k; i++) //第0天收益
  {
    dp[0][i][0] = 0;
    dp[0][i][1] = -prices[0];
  }
  for (int i = 1; i < n; i++) {
    for (int j = k; j > 0; j--) {
      dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
      dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
    }
  }
  return dp[n - 1][k][0];
}

int maxProfit_1(int k, vector<int> &prices) {
  if (prices.empty())
    return 0;
  int n = prices.size();
  if (k >= n / 2)
    return maxProfit_mul(prices);
  int dp[k + 1][2];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= k; i++) {
    dp[i][0] = 0;
    dp[i][1] = -prices[0];
  }
  for (int i = 1; i < n; i++) {
    for (int j = k; j > 0; j--) {
      dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
      dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]);
    }
  }
  return dp[k][0];
}

int main() {}