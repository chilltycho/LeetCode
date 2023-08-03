/*可用2*1小矩形横着或竖着去覆盖更大矩形，问用n个2*1的小举行无重叠覆盖一个
2*n的大矩形，从同一个方向看共有多少不同方法。*/
#include <vector>
using namespace std;
int rectCover(int number) {
  vector<int> dp(number + 1, 0);
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= number; i++)
    dp[i] = dp[i - 1] + dp[i - 2];
  return dp[number];
}