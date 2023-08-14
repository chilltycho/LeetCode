//给定非空字符串s和包含非空单词列表的wordDict，在字符串中增加空格来构建句子，使句子所有单词都在词典中,字典中无重复单词
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
// dp[i]表示字符串s前i个字符组成字符串s[0..i-1]是否能拆成若干字典中单词
// dp[i]=dp[j]&&check(s[j..i-1])
bool wordBreak(string s, vector<string> &wordDict) {
  unordered_set<string> wordDictSet;
  for (auto w : wordDict) {
    wordDictSet.insert(w);
  }
  vector<bool> dp(s.size() + 1, false);
  dp[0] = true; //空字符串
  for (int i = 1; i <= s.size(); i++) {
    for (int j = 0; j < i; j++)
      if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
        dp[i] = true;
        break;
      }
  }
  return dp[s.size()];
}

int main() {
  string s = "leetcode";
  vector<string> wordDict{"leet", "code"};
  cout << wordBreak(s, wordDict);
}