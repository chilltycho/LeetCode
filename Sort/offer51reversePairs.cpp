//在数组中两个数字，若前面大于后面，则组成逆序对，求数组中逆序对总数
#include <iostream>
#include <vector>
using namespace std;

// 暴力法
int reversePairs_vio(vector<int> &nums) {
  int res = 0;
  int len = nums.size();
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++)
      if (nums[i] > nums[j])
        res++;
  }
  return res;
}

/**借助归并排序统计逆序数
 * 合并两个有序数组，利用数组的部分有序性。
 * 前面【分】的时候什么都不做，【合】的过程计算【逆序对】个数。
 * 所有【逆序对】来于三部分：1.左边区间逆序对 2.右边区间逆序对 3.横跨两区间逆序对
 */
int reverse_cnt = 0;
void merge(vector<int> &nums, int L, int mid, int R) {
  vector<int> rec;
  int i = L, j = mid + 1;
  while (i <= mid && j <= R) {
    if (nums[i] <= nums[j]) {
      rec.push_back(nums[i]);
      i++;
    } else {
      reverse_cnt += (mid - i + 1); // i至mid都是贡献逆序的 都是大的
      rec.push_back(nums[j]);
      j++;
    }
  }
  while (i <= mid)
    rec.push_back(nums[i++]);
  while (j <= R)
    rec.push_back(nums[j++]);
  for (int i = 0; i < rec.size(); i++)
    nums[L + i] = rec[i];
}

void mergesort(vector<int> &nums, int L, int R) {
  if (L < R) {
    int mid = (L + R) >> 1;
    mergesort(nums, L, mid);
    mergesort(nums, mid + 1, R);
    merge(nums, L, mid, R);
  }
}

int reversePairs(vector<int> &nums) {
  auto len = nums.size();
  if (len < 2)
    return 0;
  mergesort(nums, 0, len - 1);
  return reverse_cnt;
}

int main() {
  vector<int> nums{1, 2, 3, 4, 5, 6, 7, 0};
  cout << reversePairs(nums);
}

