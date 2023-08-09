/*h指数指n篇论文中总共有h篇论文分别被引用了至少h次，其余的n-h少于h次
输入[0,1,3,5,6] 输出3*/
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int hIndex(vector<int> &citations) { 
  //暴力法，升序排列
  int len = citations.size();
  for (int i = 0; i < len; i++) {
    if (citations[i] >= (len - i))
      return len - i;
  }
  return 0;
}

int hIndex_bi(vector<int> &citations) {
  int len = citations.size();
  int l = 0, r = len;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (citations[m] < len - m)
      l = m + 1;
    else
      r = m;
  }
  if (l == len)
    return 0;
  return len - l;
}

int main() {
  vector<int> vi{0, 1, 3, 5, 6};
  assert(3 == hIndex_bi(vi));
}