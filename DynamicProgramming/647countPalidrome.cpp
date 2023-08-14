// 计算字符串中有多少回文子串
#include <iostream>
#include <vector>
using namespace std;

int countSubstring(string s) {
  vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
  int res = 0;
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j <= i; ++j) {
      if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1])) {
        dp[j][i] = true;
        ++res;
      }
    }
  }
  return res;
}

//若传入重合索引，长度为奇数。若传入相邻索引，长度为偶数
int centerSpred(string &s, int left, int right) {
  auto size = s.size();
  auto i = left, j = right;
  int res = 0;
  while (i >= 0 && j < size) {
    if (s[i] == s[j]) {
      ++res;
      i--;
      j++;
    } else
      break;
  }
  return res;
}

int countSubstring_1(string s) {
  int res = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (i == s.size() - 1)
      res += centerSpred(s, i, i);
    else
      res += centerSpred(s, i, i) + centerSpred(s, i, i + 1);
  }
  return res;
}

/*
Manacher算法：
线性时间内求解最长回文子串的算法。
对奇数长度和偶数长度问题，变为奇数长度。
#a#b#a#a#, 2len+1

用f(i)表示以i位为回文中心，可拓展出的最大回文半径，f(i)-1为以i为中心的最大回文串长度
假设已经计算好了[1,i-1]区间内所有点的f([1,i-1]这些点作为回文中心时的最大半径)，则也知道了
[1,i-1]拓展出的回文达到最大半径时的回文右端点。如i=4时f(i)=5,则右端点为4+5-1=8。

Manacher算法维护[当前最大的回文的右端点rm]和这个回文右端点对应的回文中心im。
*/
int Manacher(string s) {
  int n = s.size();
  string t = "$#";
  for (const char &c : s) {
    t += c;
    t += '#';
  }
  n = t.size();
  t += '!';

  auto f = vector<int>(n);
  int iMax = 0, rMax = 0, ans = 0;
  for (int i = 1; i < n; ++i) {
    // 初始化 f[i]
    f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
    // 中心拓展
    while (t[i + f[i]] == t[i - f[i]])
      ++f[i];
    // 动态维护 iMax 和 rMax
    if (i + f[i] - 1 > rMax) {
      iMax = i;
      rMax = i + f[i] - 1;
    }
    // 统计答案, 当前贡献为 (f[i] - 1) / 2 上取整
    ans += (f[i] / 2);
  }
  return ans;
}