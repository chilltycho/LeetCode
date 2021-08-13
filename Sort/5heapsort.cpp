#include <vector>
#include <iostream>
using namespace std;
/*时间复杂度：NlogM, M. 其中N为输入规模，M为想找最大或最小数量。插入logN，删除logN*/
void heapify(vector<int> &arr, int n, int i)
{
    // 最大元素为i
    auto largest = i;
    auto l = 2 * i + 1; // 左子节点
    auto r = 2 * i + 2; // 右子节点
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

void heapsort(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; --i) // 建立堆，对所有父节点，保证比子节点小，最大堆
        heapify(arr, n, i);              // O(n)次调用heapify, heapify:O(log(n)
    cout << "堆：" << endl;
    for (auto c : arr)
        cout << c << ' ';
    cout << endl;
    for (int i = n - 1; i > 0; --i) // 弹出根节点
    {
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
int main()
{
    vector<int> vi{4, 10, 3, 5, 1};
    heapsort(vi, vi.size());
    for (auto c : vi)
        cout << c << ' ';
    cout << endl;
}