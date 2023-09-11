// 建堆O(n)，每个节点堆化O(logn), n/2+1个节点堆化O(n)，
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &nums) {
  for (auto c : nums) {
    cout << c << ' ';
  }
  cout << endl;
}

/*时间复杂度：NlogM, M.
 * 其中N为输入规模，M为想找最大或最小数量。插入logN，删除logN*/
void heapify(vector<int> &arr, int n, int i) {
  print(arr);
  // 最大元素为i
  int largest = i;   // 根节点
  int l = 2 * i + 1; // 左子节点
  int r = 2 * i + 2; // 右子节点
  if (l < n && arr[l] > arr[largest])
    largest = l;
  if (r < n && arr[r] > arr[largest])
    largest = r;
  if (largest != i) // 根节点不是最大
  {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

void heapsort(vector<int> &arr, int n) {
  // 建立堆，对所有父节点，保证比子节点小，最大堆
  for (int i = n / 2 - 1; i >= 0; --i) {
    // 从左下角三角堆开始
    heapify(arr, n, i);
  }
  cout << "已构建堆 " << endl;
  // 将根节点（最大元素）不断交换到末尾
  for (int i = n - 1; i > 0; --i) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}
/*
            4
          /    \
         10     3
         / \   / \
        5   1
*/
int main() {
  vector<int> vi{4, 10, 3, 5, 1};
  heapsort(vi, vi.size());
  
}
