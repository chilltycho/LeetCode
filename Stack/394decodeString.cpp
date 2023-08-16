/*
输入：s="3[a]2[bc]"
输出："aaabcbc"

输入："3[a2[c]]"
输出："accaccacc"
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 括号内嵌套括号，需从内向外生成字符串，和栈先入后出特性对应

/*
c为数字字符，转化为数字multi
c为字母：res尾部添加c
c为[，将multi和res入栈
*/
string decodeString(string s) {
  string res{};
  stack<pair<int, string>> si;
  int multi = 0;
  for (auto c : s) {
    if (c == '[') {
      si.emplace(multi, res);
      multi = 0;
      res.clear();
    } else if (c == ']') {
      string tmp{};
      auto cur_multi = si.top().first;
      cout << cur_multi << endl;
      while (cur_multi) {
        tmp += res;
        --cur_multi;
      }
      res = si.top().second + tmp;
      si.pop();
    } else if (c >= '0' && c <= '9')
      multi = multi * 10 + c - '0';
    else
      res.push_back(c);
  }
  return res;
}

int main() {
  auto res = decodeString("100[lee]");
  cout << res << endl;
}

