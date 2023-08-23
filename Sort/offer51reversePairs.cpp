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

int res = 0;

void merge1(vector<int> &nums, int l, int m, int r) {
  vector<int> tmp;
  int i = l, j = m + 1;
  cout << "l " << l << " m " << m << " r " << r << endl;
  while (i <= m && j <= r) {
    if (nums[i] <= nums[j]) {
      tmp.push_back(nums[i++]);
    } else {
      tmp.push_back(nums[j++]);
      res += (m - i + 1);
    }
    cout << "l " << l << " m " << m << " r " << r << endl;
    cout << "i " << i << " j " << j << " r " << r << endl;
  }
  while (i <= m) {
    tmp.push_back(nums[i++]);
  }
  while (j <= r) {
    tmp.push_back(nums[j++]);
  }
  for (int h = 0; h < tmp.size(); h++) {
    nums[l + h] = tmp[h];
  }
}

void mergesort(vector<int> &nums, int l, int r) {
  if (l >= r) {
    return;
  }
  int m = l + (r - l) / 2;
  cout << m << endl;
  mergesort(nums, l, m);
  mergesort(nums, m + 1, r);
  merge1(nums, l, m, r);
}

int reversePairs(vector<int> &nums) {
  mergesort(nums, 0, nums.size() - 1);
  return res;
}

int main() {
  vector<int> nums{7,5,6,4};
  cout << reversePairs(nums);
}

