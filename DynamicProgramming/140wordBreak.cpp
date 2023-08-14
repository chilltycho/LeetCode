//给定非空字符串s和包含非空单词列表的wordDict，在字符串中增加空格来构建句子，使句子所有单词都在词典中
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_map<int, vector<string>> memo;

vector<string> dfs(string &s, int start, unordered_set<string> &dict) {
  if (start == s.size())
    return {""};
  if (memo.count(start))
    return memo[start];
  vector<string> res;
  for (int i = start; i < s.size(); i++) {
    string prefix = s.substr(start, i - start + 1);
    if (dict.count(prefix)) {
      auto suffixed = dfs(s, i + 1, dict);
      for (auto &suffix : suffixed) {
        auto str = prefix;
        if (!suffix.empty())
          str += ' ' + suffix;
        res.push_back(str);
      }
    }
  }
  memo[start] = res;
  return memo[start];
}

vector<string> wordBreak(string s, vector<string> &wordDict) {
  unordered_set<string> dict(wordDict.begin(), wordDict.end());
  vector<string> res;
  return dfs(s, 0, dict);
}

unordered_set<string> dct;
vector<string> path;
vector<string> res;
void dfs(string &s, int depth) {
  if (depth == s.size()) {
    return res;
  }
  for (int i = depth; i < s.size(); i++) {
    string word=s.substr(i,i-depth+1);
    if(dct.count(word)){
        
    }
  }
}

int main() {
  string s = "catsanddog";
  vector<string> wordDict{"cat", "cats", "and", "sand", "dog"};
  auto res = wordBreak(s, wordDict);
  for (auto &c : res)
    cout << c << ' ';
}