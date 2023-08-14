/*给定正整数，找到若干完全平方数(1,4,9...)使和为n。需让组成和的完全平方数个数最少*/
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
// dp[i]=min(dp[i],dp[i-j*j]+1)
int numSquares(int n) {
  if (n == 0)
    return 1;
  vector<int> dp(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    // 最多都是1组成
    dp[i] = i;
    for (int j = 1; i - j * j >= 0; j++) {
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }
  return dp[n];
}

int main() {
  assert(3 == numSquares(12));
  assert(2 == numSquares(13));
}
