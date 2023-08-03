// 找出三个整数，使得它们的和与target最接近，返回这三个数的和。假定每组输入只存在唯一答案
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int threeSumClosest(vector<int> &nums, int target) {
  sort(nums.begin(), nums.end());
  int dis = INT_MAX;
  int res = INT_MAX;
  int len = nums.size();
  for (int first = 0; first < len - 2; first++) {
    if (first > 0 && nums[first] == nums[first - 1])
      continue;
    int l = first + 1;
    int r = len - 1;
    while (l < r) {
      int sum = nums[first] + nums[l] + nums[r];
      if (sum == target)
        return target;
      else if (sum > target) {
        r--;
        while (l < r && nums[r] == nums[r + 1])
          r--;
      } else {
        l++;
        while (l < r && nums[l] == nums[l - 1])
          l++;
      }
      int ndis = abs(sum - target);
      if (ndis < dis) {
        res = sum;
        dis = ndis;
      }
    }
  }
  return res;
}

int main() {}