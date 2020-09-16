#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

int partition(vector<int> &a, int l, int r)
{
    int x = a[r]; //x为哨值
    int i = l - 1;
    for (int j = l; j < r; ++j)
    {
        if (a[j] <= x)
            swap(a[++i], a[j]);
    }
    swap(a[i + 1], a[r]);
    return i + 1;
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
    cout << findKthLargest(vi, 2);
}