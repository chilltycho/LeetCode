#include <iostream>
#include <vector>
using namespace std;

void printnum(vector<int> &nums) {
  for (auto &c : nums) {
    cout << c << ' ';
  }
  cout << endl;
}

void bubbleSort(vector<int> &nums) {
  int len = nums.size();
  for (int i = len - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (nums[j] > nums[j + 1]) {
        swap(nums[j], nums[j + 1]);
      }
    }
  }
}

void insertSort(vector<int> &nums) {
  int len = nums.size();
  for (int i = 1; i < len; i++) {
    int new_card = nums[i];
    int j = i;
    while (j > 0 && nums[j - 1] > new_card) {
      nums[j] = nums[j - 1];
    }
    nums[j] = new_card;
  }
}

int partition(vector<int> &nums, int l, int r) {
  int pivot = nums[l];
  int lt = l + 1, gt = r;
  while (true) {
    while (lt <= r && nums[lt] < pivot) {
      ++lt;
    }
    while (gt > l && nums[gt] > pivot) {
      --gt;
    }
    if (lt >= gt) {
      break;
    }
    swap(nums[lt++], nums[gt--]);
  }
  swap(nums[l], nums[gt]);
  return gt;
}

void quickSort(vector<int> &nums, int l, int r) {
  if (l >= r) {
    return;
  }
  int m = partition(nums, l, r);
  quickSort(nums, l, m - 1);
  quickSort(nums, m + 1, r);
}

void merge(vector<int> &nums, int l, int m, int r) {
  vector<int> vec;
  int i = l, j = m + 1;
  while (i <= m && j <= r) {
    if (nums[i] <= nums[j]) {
      vec.push_back(nums[i++]);
    } else {
      vec.push_back(nums[j++]);
    }
  }
  while (i <= m) {
    vec.push_back(nums[i++]);
  }
  while (j <= r) {
    vec.push_back(nums[j++]);
  }
  for (int i = 0; i < vec.size(); i++) {
    nums[l + i] = vec[i];
  }
}

void mergeSort(vector<int> &nums, int l, int r) {
  if (l >= r) {
    return;
  }
  int m = l + (r - l) / 2;
  mergeSort(nums, l, m);
  mergeSort(nums, m + 1, r);
  merge(nums, l, m, r);
}

void heapify(vector<int> &nums, int i, int len) {
  printnum(nums);
  int largest = i;
  int l = i * 2 + 1;
  int r = i * 2 + 2;
  if (l < len && nums[l] > nums[largest]) {
    largest = l;
  }
  if (r < len && nums[r] > nums[largest]) {
    largest = r;
  }
  if (largest != i) {
    swap(nums[i], nums[largest]);
    heapify(nums, largest, len);
  }
}

void heapSort(vector<int> &nums, int len) {
  for (int i = len / 2 - 1; i >= 0; i--) {
    heapify(nums, i, len);
  }
  cout << " heap build " << endl;
  for (int i = len - 1; i > 0; i--) {
    swap(nums[0], nums[i]);
    heapify(nums, 0, i);
  }
}

int main() {
  vector<int> vi{4, 7, 2, 3, 5, 1, 8, 6};
  heapSort(vi, vi.size());
  printnum(vi);
}
