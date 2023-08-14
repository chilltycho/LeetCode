// 最长公共子序列
#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
  if (text1.empty() || text2.empty())
    return 0;
  auto m = text1.size();
  auto n = text2.size();
  int dp[m + 1][n + 1];
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else {
        if (text1[i - 1] == text2[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[m][n];
}

int main() {
  string s = "abcde", t = "ace";
  cout << longestCommonSubsequence(s, t) << endl;
}