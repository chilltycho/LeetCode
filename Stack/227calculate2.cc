// 计算器，只有+,-,*,/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int calculate(string &s) {
  int n = s.size();
  stack<int> stk;
  char sign = '+';
  long num = 0;
  long ans = 0;
  int i = 0;
  while (i < n) {
    if (s[i] == ' ')
      ++i;
    else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
      sign = s[i];
      ++i;
    } else {
      while (i < n && s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + s[i] - '0';
        ++i;
      }
      if (sign == '-')
        num = -num;
      else if (sign == '*') {
        num = num * stk.top();
        stk.pop();
      } else if (sign == '/') {
        num = stk.top() / num;
        stk.pop();
      }
      stk.push(num);
      num = 0;
    }
  }
  while (stk.size()) {
    ans += stk.top();
    stk.pop();
  }
  return ans;
}

int main() {
  string s{"3+2*2"};
  cout << calculate(s) << endl;
}

