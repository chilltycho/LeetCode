/*给定排序好数组，两整数k,x，从数组中找到最靠近x（两数之差最小）的k个数。返回结果，需按升序排好。*/
#include <cassert>
#include <vector>
using namespace std;

// 双指针，从两端开始
vector<int> findClosestElements(vector<int> &arr, int k, int x) {
  int len = arr.size();
  int left = 0;
  int right = len - 1;
  int removeNums = len - k; // 应跳过的元素个数
  while (removeNums > 0) {
    if (x - arr[left] <= arr[right] - x)
      right--;
    else
      left++;
    removeNums--;
  }
  vector<int> res;
  for (int i = left; i <= right; i++)
    res.push_back(arr[i]);
  return res;
}

// 二分法，找左边界索引，k个元素，左边界区间[0,size-k]
vector<int> findClosestElements_bi(vector<int> &arr, int k, int x) {
  int len = arr.size();
  int left = 0;
  int right = len - k;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (x - arr[mid] > arr[mid + k] - x) // 左索引差值>右索引差值，右移
      left = mid + 1;
    else
      right = mid;
  }
  vector<int> res;
  for (int i = left; i < left + k; i++)
    res.push_back(arr[i]);
  return res;
}

int main() {
  vector<int> vi{1, 2, 3, 4, 5};
  vector<int> res{1, 2, 3, 4};
  assert(res == findClosestElements_bi(vi, 4, 3));

  vector<int> vi1{1, 2, 3, 4, 5};
  vector<int> res1{1, 2, 3, 4};
  assert(res1 == findClosestElements(vi1, 4, 1));
}