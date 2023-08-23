/*给定字符串s，非空字符串p，找到s中所有是p的字母异位词的子串，返回这些子串的起始索引*/
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {
  vector<int> res;
  if (s.size() == 0 || p.size() == 0 || s.size() < p.size())
    return res;
  int needs[128]{0};
  int window[128]{0};
  for (const auto &c : p)
    needs[c]++;

  for (int left = 0, right = 0; right < s.size(); right++) {
    window[s[right]]++;
    //窗口中包含s[right]以外字符,窗口右移
    while (window[s[right]] > needs[s[right]]) {
      window[s[left]]--;
      left++;
    }
    //完全匹配
    if (right - left + 1 == p.size())
      res.push_back(left);
  }
  return res;
}

int main() {
  //  vector<int> res{0, 6};
  // vector<int> res1{0, 1, 2};
  //索引0开始的子串是"cba"，是"abc"异位词。索引6开始子串是"bac",是"abc"异位词
  auto res = findAnagrams("cbaebabacd", "abc");
  auto res1 = findAnagrams("abab", "ab");
  for (auto c : res)
    cout << c << ' ';
}