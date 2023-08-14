//给定字符串s和字符串t，计算s的子序列中t出现的次数。
#include <iostream>
#include <vector>
using namespace std;
// dp[i][j]代表t前i字符可由s前j字符串组成最多个数
// s[j]==t[i], dp[i][j]=dp[i-1][j-1]+dp[i][j-1]
// s[j]!=t[i], dp[i][j]=dp[i][j-1]
int numDistinct(string s, string t) {
  int n1 = s.size();
  int n2 = t.size();
  vector<vector<int>> dp(n2 + 1, vector<int>(n1 + 1, 0));
  for (int j = 0; j <= n1; j++) // t为空
    dp[0][j] = 1;
  for (int i = 1; i <= n2; i++) {
    for (int j = 1; j <= n1; j++) {
      if (s[j - 1] == t[i - 1])
        dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
      else
        dp[i][j] = dp[i][j - 1];
    }
  }
  return dp[n2][n1];
}


