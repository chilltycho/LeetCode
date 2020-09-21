//给定排序数组和目标值，在数组中找到目标值，并返回索引，若不存在，返回将被按顺序插入的位置
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    if (nums.empty())
        return 0;
    int len = nums.size();
    int left = 0;
    int right = len - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main()
{
    vector<int> nums{1, 3, 5, 6};
    assert(2 == searchInsert(nums, 5));
    assert(1 == searchInsert(nums, 2));
    assert(4 == searchInsert(nums, 7));
    assert(0 == searchInsert(nums, 0));
}