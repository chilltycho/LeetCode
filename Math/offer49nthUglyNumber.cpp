//只包含因子2,3,5的数称为丑数，求从小到大第n个丑数。1是丑数
#include <iostream>
#include <vector>
using namespace std;

int nthUglyNumber(int n) {
  if (n <= 0)
    return 0;
  int dp[n];
  dp[0] = 1;
  //距离丑数i最近的丑数索引，要么是*2得来，要么*3,要么*5
  int a = 0, b = 0, c = 0;
      
  for (int i = 1; i < n; i++) {
    int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
    dp[i] = min(n2, min(n3, n5)); //最近的总是较小的那个丑数
    if (dp[i] == n2)
        a++;
    if (dp[i] == n3)
        b++;
    if (dp[i] == n5)
        c++;
  }
  return dp[n - 1];
}
