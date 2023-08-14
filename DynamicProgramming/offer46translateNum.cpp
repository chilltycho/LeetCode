//给定数字，将0翻译为'a',1翻译为'b',25翻译为'z'，计算一个数字有多少翻译方法
#include <iostream>
#include <vector>
using namespace std;
/*num=x1x2...xn
设x1x2..xi-2翻译数量为f(i-2)
设x1x2...xi-1翻译数量为f(i-1)
则整体翻译x1x2..xi方案数为f(i-2)
单独翻译xi时方案数f(i-1)

f(i)=f(i-2)+f(i-1) 当xi-1xi可被翻译
f(i)=f(i-1) xi-1xi不可翻译
*/
int translateNum(int num) {
  string src = to_string(num);
  vector<int> dp(src.size(), 0);
  if (src.size() < 2) {
    return src.size();
  }
  dp[0] = 1;
  if (src.substr(0, 2) <= "25") {
    dp[1] = 2;
  } else {
    dp[1] = 1;
  }
  for (int i = 2; i < src.size(); i++) {
    if (src.substr(i - 1, 2) <= "25" && src[i - 1] != '0') {
      dp[i] = dp[i - 1] + dp[i - 2];
    } else {
      dp[i] = dp[i - 1];
    }
  }
  return dp[src.size() - 1];
}

int translateNum_1(int num) {
  string src = to_string(num);
  int p = 0, q = 0, r = 1;
  for (int i = 0; i < src.size(); i++) {
    p = q;
    q = r;
    r = 0;
    r += q;
    if (i == 0)
      continue;
    if (src.substr(i - 1, 2) <= "25" && src[i - 1] != '0')
      r += p;
  }
  return r;
}

int main() { cout << translateNum(1) << endl; }