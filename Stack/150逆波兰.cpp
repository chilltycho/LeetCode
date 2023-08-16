#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isNum(string &s) {
  return !(s == "+" || s == "-" || s == "/" || s == "*");
}
int evalRPN(vector<string> &tokens) {
  stack<int> si;
  for (auto t : tokens) {
    if (isNum(t))
      si.push(atoi(t.c_str()));
    else {
      auto num2 = si.top();
      si.pop();
      auto num1 = si.top();
      si.pop();
      if (t == "+")
        si.push(num1 + num2);
      else if (t == "-")
        si.push(num1 - num2);
      else if (t == "*")
        si.push(num1 * num2);
      else if (t == "/")
        si.push(num1 / num2);
    }
  }
  return si.top();
}

int main() {
  vector<string> vi{"4", "13", "5", "/", "+"};
  cout << evalRPN(vi) << endl;
}

