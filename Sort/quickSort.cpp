#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int> &nums, int l, int r)
{
    int temp = nums[l];
    nums[l] = nums[r];
    nums[r] = temp;
}

int partition(vector<int> &nums, int left, int right)
{
    int pivot = nums[left]; //基准值
    int lt = left;          //less than
    //循环不变量：确保[left+1,lt]<pivot, [lt+1,i]>=pivot
    for (int i = left + 1; i <= right; i++)
    {
        if (pivot > nums[i])
        {
            lt++;
            swap(nums, i, lt);
        }
    }
    swap(nums, left, lt);
    return lt;
}
void quickSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;//小区间使用插入排序可提高效率
    int pIndex = partition(nums, left, right);
    quickSort(nums, left, pIndex - 1);
    quickSort(nums, pIndex + 1, right);
}

int main()
{
    vector<int> nums{3, 4, 1, 2, 5};
    quickSort(nums, 0, nums.size() - 1);
    for (auto c : nums)
        cout << c << ' ';
}