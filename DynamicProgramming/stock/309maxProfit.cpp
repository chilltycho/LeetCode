/*不能同时参与多笔交易（必须在再次购买前出售掉之前股票）
卖出股票后，不能在第二天买入股票（冷冻期为1天）*/
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
  if (prices.empty())
    return 0;
  int n = prices.size();
  int dp[n][2];
  dp[0][0] = 0;
  dp[0][1] = -prices[0];
  for (int i = 1; i < n; i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
    dp[i][1] = max(dp[i - 1][1], (i >= 2 ? dp[i - 2][0] : 0) - prices[i]);
  }
  return dp[n - 1][0];
}

int maxProfit_1(vector<int> &prices) {
  if (prices.empty()) {
    return 0;
  }
  int prevProfit0 = 0, profit0 = 0, profit1 = -prices[0];
  int length = prices.size();
  for (int i = 1; i < length; i++) {
    int nextProfit0 = max(profit0, profit1 + prices[i]);
    int nextProfit1 = max(profit1, prevProfit0 - prices[i]);
    prevProfit0 = profit0;
    profit0 = nextProfit0;
    profit1 = nextProfit1;
  }
  return profit0;
}