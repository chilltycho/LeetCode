/*给定字符串s，将s分割为子串，使每个子串都是回文串*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<string>> res;
vector<string> path;
vector<vector<bool>> dp;

void prePro(string &s, int l, int r) {
  while (l >= 0 && r < s.size() && s[l] == s[r]) {
    dp[l][r] = true;
    --l, ++r;
  }
}

void dfs(string &s, int start) {
  if (start == s.size()) {
    res.push_back(path);
    return;
  }
  for (int i = start; i < s.size(); ++i) {
    if (!dp[start][i])
      continue;
    path.push_back(s.substr(start, i + 1 - start));
    dfs(s, i + 1);
    path.pop_back();
  }
}

vector<vector<string>> partition(string s) {
  int len = s.size();
  if (len == 0)
    return res;
  dp = vector<vector<bool>>(len, vector<bool>(len, false));
  for (int i = 0; i < len; ++i) {
    prePro(s, i, i);
    prePro(s, i, i + 1);
  }
  dfs(s, 0);
  return res;
}

int main() {
  string s = "aab";
  partition(s);
  for (auto v : res) {
    for (auto s : v)
      cout << s << ' ';
    cout << endl;
  }
}