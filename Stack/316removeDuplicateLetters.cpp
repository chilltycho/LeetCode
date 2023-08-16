/*给定字符串s，去除字符串中重复的字母，且保证返回结果的字典序最小（不打乱相对顺序）*/
#include <iostream>
#include <vector>
using namespace std;
// 递增单调栈
string removeDuplicateLetters(string s) {
  vector<int> vis(128), num(128); // 是否已经遍历，剩余次数
  for (auto c : s)
    ++num[c];
  string stk;
  for (char c : s) {
    // c未遍历过
    if (!vis[c]) {
      while (!stk.empty() && stk.back() > c && num[stk.back()] > 0) {
        vis[stk.back()] = 0;
        stk.pop_back();
      }
      vis[c] = 1;
      stk.push_back(c);
    }
    num[c] -= 1;
  }
  return stk;
}

int main() {
  string s{"bcabc"};
  cout << removeDuplicateLetters(s) << endl;
}
