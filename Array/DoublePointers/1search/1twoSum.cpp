#include <iostream>
#include <vector>
using namespace std;
/*给定一个已按升序排列的有序数组，找到两个数使得他们相加之和等于目标数
index1,index2 答案唯一
输入nums[2,7,11,15] target=9 输出[1,2]*/
vector<int> twoSum(vector<int> &nums, int target) {
  int i = 0;
  int j = nums.size() - 1;
  while (i < j) {
    int sum = nums[i] + nums[j];
    if (sum < target) {
      i++;
    } else if (sum > target) {
      /*a[i]+a[j]大了，应去找更小的两个数，但a[i]已经是最小，故j左移*/
      j--;
    } else {
      return vector<int>{i + 1, j + 1};
    }
  }
  return vector<int>{-1, -1};
}

int main() {
  vector<int> nums{2, 7, 11, 15};
  auto res = twoSum(nums, 18);
  for (auto c : res)
    cout << c << ' ';
}