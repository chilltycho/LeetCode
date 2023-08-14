// 每种硬币无限，求兑换使用最少硬币数
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// 直接dfs
int res = INT_MAX;
void dfs(vector<int> &coins, int amount, int count) {
  if (amount < 0)
    return;
  if (amount == 0)
    res = min(res, count);
  for (auto &c : coins)
    dfs(coins, amount - c, count + 1);
}

int coinChange(vector<int> &coins, int amount) {
  if (coins.empty())
    return -1;
}

//记忆化搜索
int dfs_1(vector<int> &coins, int amount, vector<int> &memo) {
  if (amount < 0)
    return -1;
  if (amount == 0)
    return 0;
  if (memo[amount] != 0)
    return memo[amount - 1];
  int minre = INT_MAX;
  for (auto &c : coins) {
    int res = dfs_1(coins, amount - c, memo);
    if (res >= 0 && res < minre)
      minre = res + 1;
  }
  memo[amount] = (minre == INT_MAX ? -1 : minre);
  return memo[amount];
}

int coinChange_1(vector<int> &coins, int amount) {
  if (coins.empty())
    return -1;
  vector<int> memo(amount + 1); // 表示amount可换取最少硬币数
  return dfs_1(coins, amount, memo);
}

int main() {
  vector<int> coins{1, 2, 5};
  int amount = 11;
  cout << coinChange_1(coins, amount);
}

