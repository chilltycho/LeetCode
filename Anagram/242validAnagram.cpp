// 给定两个字符串s，t，判断t是否为s变位词，即是否可以将字母重新排列得到t
#include <cassert>
#include <iostream>
#include <unordered_map>
using namespace std;
// 只包含小写字母
bool isAnagram_1(string s, string t) {
  if (s.size() != t.size())
    return false;
  int Smap[26]{0};
  for (int i = 0; i < s.size(); i++)
    Smap[s[i] - 'a']++;
  for (int i = 0; i < t.size(); i++) {
    if (Smap[t[i] - 'a'] == 0)
      return false;
    Smap[t[i] - 'a']--;
  }
  return true;
}

int main() {
  assert(isAnagram_1("anagram", "nagaram"));
  assert(!isAnagram_1("rat", "car"));
}