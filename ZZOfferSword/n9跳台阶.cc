// 可跳1..n级，求跳上n级台阶跳法数
#include <vector>
using namespace std;
int jumpFloorII(int number) {
  vector<int> dp(number + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= number; i++) {
    for (int j = 1; j <= i; j++)
      dp[i] += dp[i - j];
  }
  return dp[number];
}