/*时间复杂度：最好最坏均为O(N^2) 空间复杂度O(1)，不稳定排序 如[5,8,5,2,9]，第一次会选择2和
 第一个5交换，导致两个5相对顺序变化*/
#include <iostream>
#include <vector>
using namespace std;
void selectSort(vector<int> &nums) {
  auto len = nums.size();
  //循环不变量：[0,i)有序
  for (size_t i = 0; i < len - 1; i++) {
    //选择[i,len-1]最小元素索引，交换到i
    size_t minIndex = i;
    for (size_t j = i + 1; j < len; j++) {
      if (nums[j] < nums[minIndex]) {
        minIndex = j;
      }
    }
    swap(nums[i], nums[minIndex]);
  }
}

int main() {
  vector<int> vi{2, 1, 5, 3};
  selectSort(vi);
  for (auto c : vi)
    cout << c << " ";
}

