// 不能偷相邻的房间
#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> &nums) {
  if (nums.empty()) {
    return 0;
  }

  vector<int> dp(nums.size() + 1, 0);
  dp[0] = 0;
  dp[1] = nums[0];
  for (int i = 2; i <= nums.size(); i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
  }
  return dp[nums.size()];
}

int rob_s(vector<int> &nums) {
  if (nums.empty())
    return 0;
  auto pre = 0, cur = nums[0], temp = 0;
  for (auto i = 2; i <= nums.size(); i++) {
    temp = cur;
    cur = max(cur, pre + nums[i - 1]);
    pre = temp;
  }
  return cur;
}

int main() {
  vector<int> nums{1, 2, 3, 1};
  cout << rob_s(nums) << endl;
}
