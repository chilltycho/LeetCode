/**
 * 输入两数组，第一个为压入顺序，判断第二个是否为为弹出顺序
 */
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isPopOrder(vector<int> &pushV, vector<int> &popV) {
  stack<int> si;
  int i = 0;
  for (auto c : pushV) {
    si.push(c);
    while (!si.empty() && si.top() == popV[i]) {
      i++;
      si.pop();
    }
  }
  return si.size() == 0;
}

int main() {
  vector<int> pu{1, 2, 3, 4, 5};
  vector<int> po{4, 3, 5, 1, 2};
  assert(!isPopOrder(pu, po));
}
