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
  if (nums.empty()) {
    return -1;
  }
  int l = 0, r = nums.size() - 1;
  while (l < r) // [l...r]里查找target
  {
    auto m = l + (r - l) / 2;
    cout << "m " << m << endl;
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
  vector<int> v4{-1, 0, 1, 2, 3, 4, 5};
  vector<int> v5{1};
  int target = 3;
  cout << binarysearch(v1, target) << "\n\n";
  cout << binarysearch(v2, target) << "\n\n";
  cout << binarysearch(v3, target) << "\n\n";
  cout << binarysearch(v4, target) << "\n\n";
  cout << binarysearch(v5, target) << "\n\n";
}
