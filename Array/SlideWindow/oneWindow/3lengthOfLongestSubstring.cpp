/*给定一个字符串，找出不含重复字符的最长子串长度*/
#include <cassert>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
  int len = s.size();
  if (len < 2)
    return len;
  int res = 1;
  int hashMap[128]{0};
  for (int left = 0, right = 0; right < len; right++) {
    hashMap[s[right]]++;
    //出现重复，右滑窗口，且减少字符相应出现次数。
    while (hashMap[s[right]] == 2) {
      hashMap[s[left]]--;
      left++;
    }
    res = max(res, right - left + 1);
  }
  return res;
}

int main() {
  assert(3 == lengthOfLongestSubstring("abcabcbb")); // abc
  assert(1 == lengthOfLongestSubstring("bbbbb"));    // b
  assert(3 == lengthOfLongestSubstring("pwwkew"));   // wke
}
