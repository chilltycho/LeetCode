/*给定一个整数数组，找到一个具有最大和的连续子数组（连续子数组最少包含一个元素）返回其最大和。*/
#include <iostream>
#include <vector>
using namespace std;

//子数组一定连续，子序列可以不连续。
/*1.正确定义子问题：f(k)表示nums[0,..k)中，以最后一个元素结尾的最大子数组和
2.递推：f(k)=max(f(k-1),0)+nums[k-1]由于子问题定义，肯定要nums[k-1]*/
int maxSubArray(vector<int> &nums) {
  int size = nums.size();
  int dp[size + 1];
  dp[0] = 0;
  int res = nums[0];
  for (int i = 1; i <= size; i++) {
    dp[i] = nums[i - 1] + max(dp[i - 1], 0);
    res = max(res, dp[i]);
  }
  return res;
}

int maxSubArray_1(vector<int> &nums) {
  int size = nums.size();
  int old = 0, newval = nums[0];
  for (int i = 1; i < size; i++) {
    old = nums[i - 1] + max(old, 0);
    newval = max(newval, old);
  }
  return newval;
}

int main() {
  vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << maxSubArray_1(nums);
}