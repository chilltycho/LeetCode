#include <stack>
using namespace std;
class MyQueue {
private:
  stack<int> in, out;

public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { in.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int res = peek();
    out.pop();
    return res;
  }

  /** Get the front element. */
  int peek() {
    if (out.empty()) {
      while (in.size()) {
        out.push(in.top());
        in.pop();
      }
    }
    return out.top();
  }

  bool empty() { return in.empty() && out.empty(); }
};
