#include <iostream>
#include <vector>
using namespace std;
/*
归并排序，平均情况O(nlogn),最好O(nlogn)，最坏O(nlogn)，空间复杂度O(n + logn)，稳定
主要是递归造成的栈空间的使用logn，和每次归并都需要将原数组归并到新数组，再拷贝回原数组，和每次归并都需要将原数组归并到新数组，再拷贝回原数组O(n)
*/
void merge(vector<int> &nums, int l, int m, int r)
{
    vector<int> tmp;
    int i = l, j = m+1;
    while (i <= m && j <= r)
    {
        if (nums[i] < nums[j])
            tmp.push_back(nums[i++]);
        else
            tmp.push_back(nums[j++]);
    }
    while (i <= m)
        tmp.push_back(nums[i++]);
    while (j <= r)
        tmp.push_back(nums[j++]);
    for (size_t i = 0; i < tmp.size(); ++i)
        nums[i + l] = tmp[i];
}

void Msort(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    Msort(nums, l, m);
    Msort(nums, m + 1, r);
    merge(nums, l, m, r);
}

int main()
{
    vector<int> vi{2, 1, 0, 5, 4, 3, 6};
    Msort(vi, 0, vi.size() - 1);
    for (auto c : vi)
        cout << c << ' ';
    cout << endl;
}