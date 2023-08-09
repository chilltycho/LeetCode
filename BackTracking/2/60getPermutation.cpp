/*n=3,[1,2,3]
所有排列情况：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
k=3，返回[2,1,3]*/
#include <iostream>
#include <vector>
using namespace std;

bool *used;
int *factorial;
vector<int> path;
// index为树深度
void dfs(int index, int n, int k) {
  if (index == n)
    // 刚好n个数时，即为答案
    return;
  // 当前层可减去的叶子
  int cnt = factorial[n - 1 - index];
  for (int i = 1; i <= n; i++) {
    if (used[i])
      // 确保每个数不重复
      continue;
    if (cnt < k) {
      k -= cnt;
      continue;
    }
    path.push_back(i);
    used[i] = true;
    dfs(index + 1, n, k);
  }
}

string getPermutation(int n, int k) {
  used = new bool[n + 1]{false};
  factorial = new int[n + 1];
  factorial[0] = 1;
  for (int i = 1; i <= n; i++) {
    factorial[i] = factorial[i - 1] * i;
  }
  dfs(0, n, k);
  string s = "";
  for (auto c : path)
    s += to_string(c);
  return s;
}

int main() {
  string res = getPermutation(3, 3);
  cout << res;
}