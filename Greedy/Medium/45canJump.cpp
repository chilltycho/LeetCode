// 假定一定能到达终点，求跳跃所需步数
#include <iostream>
#include <vector>
using namespace std;

int jump_1(vector<int> &nums) {
  int res = 0;
  int start = 0;
  int end = 1;
  while (end < nums.size()) {
    int maxPos = 0;
    for (int i = start; i < end; i++) {
      maxPos = max(maxPos, i + nums[i]);
    }
    start = end;
    end = maxPos + 1;
    ++res;
  }
  return res;
}

int jump(vector<int> &nums) {
  int tom = 0; // 当前覆盖最远下标
  int res = 0; // 走的最大步数
  int end = 0; // 下步覆盖最远距离下标
  for (int i = 0; i < nums.size() - 1; ++i) {
    tom = max(i + nums[i], tom);
    if (i == end) // 到达某点能到的最远点，步数加1
    {
      end = tom; // 更改新一步能到最远点
      ++res;
    }
  }
  return res;
}

int main() {
  // 第0步end=0，第1步，end
  vector<int> nums{2, 3, 1, 1, 4};
  cout << jump(nums) << endl;
}