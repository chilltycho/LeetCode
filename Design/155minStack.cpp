//最小栈
#include <climits>
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
  stack<int> datastack;
  stack<int> minstack;

public:
  MinStack() { minstack.push(INT_MAX); }
  void push(int x) {
    datastack.push(x);
    minstack.push(min(minstack.top(), x));
  }
  void pop() {
    datastack.pop();
    minstack.pop();
  }
  int top() { return datastack.top(); }
  int getMin() { return minstack.top(); }
};

