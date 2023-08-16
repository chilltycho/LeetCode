// 带括号的
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
unordered_map<char, int> um{{'-', 1}, {'+', 1}, {'*', 2},
                            {'/', 2}, {'%', 2}, {'^', 3}};
// 替换空格
void replace(string &s) {
  int pos = s.find(" ");
  while (pos != -1) {
    s.replace(pos, 1, "");
    pos = s.find(" ");
  }
}

void calc(stack<int> &nums, stack<char> &ops) {
  if (nums.size() < 2 || ops.empty())
    return;
  int b = nums.top();
  nums.pop();
  int a = nums.top();
  nums.pop();
  char op = ops.top();
  ops.pop();
  int ans = 0;
  if (op == '+')
    ans = a + b;
  else if (op == '-')
    ans = a - b;
  else if (op == '*')
    ans = a * b;
  else if (op == '/')
    ans = a / b;
  else if (op == '%')
    ans = a % b;
  nums.push(ans);
}

int calculate(string s) {
  stack<int> nums;
  nums.push(0);
  replace(s);
  stack<char> ops;

  int n = s.size();
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (c == '(')
      ops.push(c);
    else if (c == ')') {
      while (!ops.empty()) {
        char op = ops.top();
        if (op != '(') // 先算括号里面的
          calc(nums, ops);
        else {
          ops.pop();
          break;
        }
      }
    } else {
      if (isdigit(c)) {
        int cur_num = 0;
        int j = i;
        while (j < n && isdigit(s[j]))
          cur_num = cur_num * 10 + (s[j++] - '0');
        nums.push(cur_num);
        i = j - 1;
      } else {
        // 处理(-的情况，添加0为(0-
        if (i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-'))
          nums.push(0);
        while (!ops.empty() && ops.top() != '(') {
          if (um[ops.top()] >= um[c]) // 栈里优先级高，先算栈里的
            calc(nums, ops);
          else
            break;
        }
        ops.push(c);
      }
    }
  }
  while (!ops.empty())
    calc(nums, ops);
  return nums.top();
}

int main() { string s{"(1+(4+5+2)-3)+(6+8)"}; }

