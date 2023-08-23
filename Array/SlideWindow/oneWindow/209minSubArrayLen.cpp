#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
// 给定含n个正整数的数组和一个正整数target，找出数组中满足其和>=target的长度最小的连续子数组，返回其长度。
int minSubArrayLen_mm(int s, vector<int> &nums) {
  if (nums.empty())
    return 0;
  int windowSum = 0;
  int min_size = nums.size() + 1;
  for (int l = 0, r = 0; r < nums.size(); r++) {
    windowSum += nums[r];
    while (windowSum >= s) {
      min_size = min(r - l + 1, min_size);
      windowSum -= nums[l];
      l++;
    }
  }
  return min_size == nums.size() + 1 ? 0 : min_size;
}

//返回大于等于target的下标
int lowerBound(vector<int> &a, int l, int r, int target) {
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (a[mid] < target)
      l = mid + 1;
    else
      r = mid;
  }
  return a[l] >= target ? l : -1;
}
//确定每个子数组开始下标后，使用二分查找。O(nlogn)
int minSubArrayLen_1(int s, vector<int> &nums) {
  if (nums.empty())
    return 0;
  int len = nums.size();
  int minLen = len + 1;
  vector<int> sums(len + 1, 0);
  for (int i = 1; i <= len; i++)
    sums[i] = sums[i - 1] + nums[i - 1]; // 前缀和
  for (int i = 1; i <= len; i++) {
    int target = s + sums[i - 1];
    int bound = lowerBound(sums, i, len, target);
    if (bound != -1)
      minLen = min(minLen, bound - i + 1);
  }
  return minLen == len + 1 ? 0 : minLen;
}

int minSubArrayLen_bru(int s, vector<int> &nums) {
  int len = nums.size();
  if (len == 0)
    return 0;
  int ans = INT32_MAX;
  for (int i = 0; i < len; i++) {
    int sum = 0;
    for (int j = i; j < len; j++) {
      sum += nums[j];
      if (sum >= s) {
        ans = min(ans, j - i + 1);
        break;
      }
    }
  }
  return ans == INT32_MAX ? 0 : ans;
}

int minSubArrayLen(int target, vector<int> &nums) {
  int all_sum = accumulate(nums.begin(), nums.end(), 0);
  if (nums.empty() || all_sum < target) {
    return 0;
  }
  int tmp_sum = 0, res = nums.size() + 1;
  for (int l = 0, r = 0; r < nums.size(); r++) {
    tmp_sum += nums[r];
    while (tmp_sum > target) {
        tmp_sum -= nums[l++];
    }
    if (tmp_sum == target) {
      res = min(res, r - l + 1);
      tmp_sum -= nums[l++];
    }
  }
  return res == nums.size() + 1 ? 0 : res;
}

int main() {
  vector<int> vi{2, 3, 1, 2, 4, 3};
  assert(2 == minSubArrayLen(7, vi)); //[4.3]符合条件
}