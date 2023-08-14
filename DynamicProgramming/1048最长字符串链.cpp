/*
给出一个单词列表，每个单词都由小写字母组成。可在一个单词任何地方加一个字母变为另一个单词。形成链
求列表最长链。
*/
#include <bits/stdc++.h>
using namespace std;
int longestStrChain(vector<string> &words) {
  sort(words.begin(), words.end(),
       [](auto a, auto b) { return a.size() < b.size(); });
  int n = words.size(), res = 1, i, j;
  unordered_map<string, int> um;
  string tmp;
  vector<int> dp(n, 1);
  for (i = 0; i < n - 1; ++i) {
    um[words[i]] = i;
    for (j = i + 1; j < n; ++j) {
      // words[i]能否增加为words[j]
      if (words[j].size() != words[i].size() + 1) {
        // 长度相差不为1
        break;
      }
      for (size_t k = 0; k < words[j].size(); ++k) {
          // words[j]减去任意一个
          tmp = words[j].substr(0, k) + words[j].substr(k + 1);
          if (um.count(tmp)) {
            dp[j] = max(dp[j], dp[um[tmp]] + 1);
            res = max(dp[j], res);
          }
        }
    }
  }
  return res;
}

int main() {
  vector<string> vi{"a", "b", "ba", "bca", "bda", "bdca"};
  assert(longestStrChain(vi) == 4); // a,ba,bda,bdca
}
