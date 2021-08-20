#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;
// O(N)
int partition(vector<int> &a, int l, int r)
{
    int pivot = rand() % (r - l + 1) + l;
    swap(a[pivot], a[l]);
    int i = l + 1, j = r;
    while (true)
    {
        while (i <= r && a[i] <= a[l])
            ++i;
        while (j > l && a[j] >= a[l])
            --j;
        if (i >= j)
            break;
        swap(a[i++], a[j--]);
    }
    swap(a[l], a[j]);
    return j;
}

int quickSelect(vector<int> &a, int l, int r, int index)
{
    //a[l..q..r]
    int q = partition(a, l, r);
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
    cout << findKthLargest(vi, 5);
}