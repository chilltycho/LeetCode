#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;
// O(N)
int partition(vector<int> &a, int l, int r)
{
    int pivot = a[l]; //基准值
    int lt = l;       //less than
    //循环不变量：确保[left+1,lt]<pivot, [lt+1,i]>=pivot
    for (int i = l + 1; i <= r; i++)
    {
        if (pivot > a[i])
        {
            lt++;
            swap(a[i], a[lt]);
        }
    }
    swap(a[l], a[lt]);
    return lt;
}

int randomPartition(vector<int> &a, int l, int r)
{
    int i = rand() % (r - l + 1) + l;
    swap(a[i], a[r]);
    return partition(a, l, r);
}

int quickSelect(vector<int> &a, int l, int r, int index)
{
    //a[l..q..r]
    int q = randomPartition(a, l, r);
    if (q == index)
    {
        return a[q];
    }
    else
    {
        return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
    }
}

int findKthLargest(vector<int> &nums, int k)
{
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
}

int main()
{
    vector<int> vi{3, 2, 1, 5, 6, 4};
    cout << findKthLargest(vi, 1);
}