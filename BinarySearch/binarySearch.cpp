#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// target能插入的第一个位置
int m_lowerbound(vector<int> &nums, int target) {
  if (nums.empty())
    return -1;
  size_t l = 0, r = nums.size();
  while (l < r) {
    auto m = l + (r - l) / 2;
    if (nums[m] < target)
      l = m + 1;
    else
      r = m;
  }
  return l; // l和r一样 可能从[0,nums.size()]
}

// target可插入最后一个位置
int m_upperbound(vector<int> &nums, int target) {
  if (nums.empty())
    return -1;
  size_t l = 0, r = nums.size();
  while (l < r) {
    auto m = l + (r - l) / 2;
    if (nums[m] <= target)
      l = m + 1;
    else
      r = m;
  }
  return l;
}

int binarysearch(vector<int> &nums, int target) {
  int l = 0, r = nums.size() - 1;
  while (l < r) // [l...r]里查找target
  {
    auto m = l + (r - l) / 2;
    if (nums[m] == target)
      return m;
    else if (nums[m] > target)
      r = m - 1;
    else
      l = m + 1;
  }
  return l;
}

int main() {
  vector<int> v1{};
  vector<int> v2{1, 2, 3};
  vector<int> v3{1, 2, 3, 4};
  vector<int> ss{-1, 0, 1, 2, 3, 4, 5};
  vector<int> vs{1};
  cout << m_lowerbound(ss, 1) << ' ' << m_upperbound(ss, 1) << endl;
}
