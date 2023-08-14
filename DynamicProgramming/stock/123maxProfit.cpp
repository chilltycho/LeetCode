#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
//最多两笔交易
int maxProfit(vector<int> &prices) {
  int n = prices.size();
  int dp[n][3][2];
  memset(dp, 0, sizeof(dp));
  dp[0][1][0] = 0;          //第一次交易，未持有
  dp[0][1][1] = -prices[0]; //第一次交易，持有
  dp[0][2][0] = 0;
  dp[0][2][1] = -prices[0];
  for (int i = 1; i < n; i++) {
    // 第二次未持有     不交易            第二次持有   + prices[i]
    dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i]);
    // 第二次持有       不交易            第一次未持有 - prices[i]   
    dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i]);
    // 第一次未持有     不交易             第一次持有  + prices[i]
    dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i]);
    // dp[i][0][0]=0
    //  第一次持有       不交易             第0次未持有 - prices[i]
    dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][0] - prices[i]);
  }
  return dp[n - 1][2][0];
}

int maxProfit_1(vector<int> &prices) {
  if (prices.empty())
    return 0;
  int dp10 = 0, dp11 = -prices[0], dp20 = 0, dp21 = -prices[0];
  int n = prices.size();
  for (int i = 1; i < n; i++) {
    dp20 = max(dp20, dp21 + prices[i]);
    dp21 = max(dp21, dp10 - prices[i]);
    dp10 = max(dp10, dp11 + prices[i]);
    dp11 = max(dp11, -prices[i]);
  }
  return dp20;
}

int main() {
  vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};
  cout << maxProfit(prices) << endl; //应为6
  vector<int> prices1{1, 2, 3, 4, 5};
  cout << maxProfit(prices1) << endl; //应为4
}