//?可匹配任何单个字符，*可匹配任意字符（包括空字符）
#include <iostream>
#include <vector>
using namespace std;
// f[i][j]:s(0,i-1)和p(0,j-1)是否匹配.
bool isMatch(string s, string p) {
  if (s.empty() && p.empty())
    return true;
  if (p.empty() && (!s.empty()))
    return false;
  auto sLen = s.size();
  auto pLen = p.size();
  vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));
  dp[0][0] = true;                      //两个空字符串
  for (size_t j = 1; j < pLen + 1; j++) // s为空,p不为空
    if (p[j - 1] == '*')
      dp[0][j] = dp[0][j - 1];

  for (size_t i = 1; i < sLen + 1; i++) {
    for (size_t j = 1; j < pLen + 1; j++) {
      if (s[i - 1] == p[j - 1] || p[j - 1] == '?') //最后字符匹配
        dp[i][j] = dp[i - 1][j - 1];
      else if (p[j - 1] == '*')                  //不匹配，但有*号
        dp[i][j] = dp[i][j - 1] || dp[i - 1][j]; //使用或不使用*号
    }
  }
  return dp[sLen][pLen];
}

