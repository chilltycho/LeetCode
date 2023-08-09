/*给定非负整数数组和整数m，将数组分成m个非空的连续子数组，设计算法使m个子数组各自和的最大值最小*/
#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>
using namespace std;

int split(vector<int> &nums, int maxIntervalSum) {
  int splits = 1; // 即使不分，也有一组
  int curIntervalSum = 0;
  for (int num : nums) {
    if (curIntervalSum + num > maxIntervalSum) {
      // 分一组
      curIntervalSum = 0;
      splits++;
    }
    curIntervalSum += num;
  }
  return splits;
}

int splitArray(vector<int> &nums, int m) {
  if (m > nums.size())
    return -1;
  int biggest = *max_element(nums.begin(), nums.end());
  int sum = accumulate(nums.begin(), nums.end(), 0);
  int left = biggest; // maxIntervalSum的最小值，每个数为一组
  int right = sum;    // maxIntervalSUm最大值，整个数组为一组
  while (left < right) {
    int mid = left + (right - left) / 2;
    int splits = split(nums, mid);
    if (splits > m) // 分组数超过要求，子数组各自的和的最大值太小
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

/*动态规划 [将数组分割为m段，求...]
 *将dp[i][j]定义为数组前i个数分割为j段所能得到的最大连续子数组和的最小值。
 *dp[i][j]=min(max(dp[k][j-1],sub[k+1,i]))
 *sub[i,j]数组nums中下标落在区间[i,j]内的数的和*/
int splitArray_dp(vector<int> &nums, int m) {
  int n = nums.size();
  vector<vector<long long>> f(n + 1,
                              vector<long long>(m + 1, __LONG_LONG_MAX__));
  vector<long long> sub(n + 1, 0);
  for (int i = 0; i < n; i++)
    sub[i + 1] = sub[i] + nums[i];
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= min(i, m); j++) {
      for (int k = 0; k < i; k++) {
        f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
      }
    }
  }
  return (int)f[n][m];
}

int main() {
  vector<int> nums{7, 2, 5, 10, 8};
  assert(18 == splitArray(nums, 2)); // 分为[7,2,5]和[10,8]
}

