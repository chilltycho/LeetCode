#include <vector>
#include <iostream>
using namespace std;
/*
归并排序，平均情况O(nlogn),最好O(nlogn)，最坏O(nlogn)，空间复杂度O(n + logn)，稳定
主要是递归造成的栈空间的使用logn，和每次归并都需要将原数组归并到新数组，再拷贝回原数组，和每次归并都需要将原数组归并到新数组，再拷贝回原数组O(n)
*/
void merge(vector<int> &nums, int L, int mid, int R)
{
    vector<int> rec;
    int i = L, j = mid + 1;
    while (i <= mid && j <= R)
    {
        if (nums[i] <= nums[j])
            rec.push_back(nums[i++]);
        else
            rec.push_back(nums[j++]);
    }
    while (i <= mid)
        rec.push_back(nums[i++]);
    while (j <= R)
        rec.push_back(nums[j++]);
    for (int i = 0; i < rec.size(); i++)
        nums[L + i] = rec[i];
}

void mergesort(vector<int> &nums, int L, int R)
{
    if (L >= R)
        return;
    int mid = (L + R) >> 1;
    mergesort(nums, L, mid);
    mergesort(nums, mid + 1, R);
    merge(nums, L, mid, R);
}

int main()
{
    vector<int> res{2, 3, 5, 1, 1, 0};
    mergesort(res, 0, res.size() - 1);
    for (auto c : res)
        cout << c << ' ';
}