//胃口值数组g,饼干尺寸数组s,求能满足的最大数量
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;
//每次见满足胃口小的,直到分完
int findContentChildren(vector<int> &g, vector<int> &s) {
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());
  size_t a = 0;
  size_t b = 0;
  int res = 0;
  while (a < g.size() && b < s.size()) {
    if (g[a] <= s[b]) {
      res++;
      a++;
      b++;
    } else
      b++;
  }
  return res;
}

int main() {
  vector<int> g{1, 2, 3};
  vector<int> s{1, 1};
  assert(1 == findContentChildren(g, s));
  vector<int> g1{1, 2};
  vector<int> s1{1, 2, 3};
  assert(2 == findContentChildren(g1, s1));
}