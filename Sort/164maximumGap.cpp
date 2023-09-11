// 给定无序数组，找出数组在排序后，相邻元素之间最大差值，若元素个数小于2,返回0
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 基数排序，先个位再十位再百位
int maximumGap(vector<int> &nums) {
  int n = nums.size();
  if (n < 2) {
    return 0;
  }
  int radix = 1; // 初始基数为1
  int maxVal = *max_element(nums.begin(), nums.end());
  // 对每位进行排序
  while (maxVal / radix) {
    vector<vector<int>> buckets(10); // 10个桶
    // 将元素按最低位放入对应桶
    for (auto c : nums) {
      buckets[(c / radix) % 10].push_back(c);
    }
    // 桶中元素放回数组
    int j = 0;
    for (int i = 0; i < 10; i++) {
      for (auto c : buckets[i]) {
        nums[j++] = c;
      }
    }
    radix *= 10;
  }

  int ret = 0;
  for (int i = 1; i < n; i++)
    ret = max(ret, nums[i] - nums[i - 1]);
  return ret;
}

int main() {
  vector<int> nums{3, 6, 9, 1};
  // 3
  cout << maximumGap(nums) << endl;
}
