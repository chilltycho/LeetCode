#include <random>
#include <vector>
#include <iostream>
using namespace std;
/*
时间复杂度为nlogn: 分治算法，每次选出哨兵，将待排序列分成两部分，一直分下去，直到只有一个元素，平均分开，相当于n个结点的二叉树，共有logn层，递归深度为logn。
空间复杂度O(logn)~O(n)：主要是递归造成的栈空间的使用，最好情况递归树深度为logn，最坏情况为n
*/
int partition(vector<int> &nums, int l, int r)
{
    auto index = rand() % (r - l + 1) + l;
    swap(nums[l], nums[index]);
    int pviot = nums[l];
    int i = l + 1, j = r;
    while (true)
    {
        while (i <= r && nums[i] <= pviot)
            i++;
        while (j > l && nums[j] >= pviot)
            j--;
        if (i > j)
            break;
        swap(nums[i++], nums[j--]);
    }
    swap(nums[l], nums[j]);
    return j;
}

void Qsort(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;
    int m = partition(nums, l, r);
    Qsort(nums, l, m - 1);
    Qsort(nums, m + 1, r);
}

int main()
{
    vector<int> nums{1, 3, 4, 2, 0, 5, 9};
    Qsort(nums, 0, nums.size() - 1);
    for (auto c : nums)
        cout << c << ' ';
}