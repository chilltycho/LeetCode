/*假定按升序排序的数组在预先某点上旋转，[0,1,2,4,5,6,7]变为[4,5,6,7,0,1,2]
搜索给定目标值，若存在，返回索引，若不存在，返回-1.数组不存在重复元素*/
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

int search_1(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if ((nums[0] > target) ^ (nums[0] > nums[m]) ^ (target > nums[m]))
            l = m + 1;
        else
            r = m;
    }
    return l == r && nums[l] == target ? l : -1;
}

int search(vector<int> &nums, int target)
{
    if (nums.empty())
        return -1;
    int len = nums.size();
    int left = 0;
    int right = len - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] >= nums[left]) //左半部分升序
        {
            if (target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else //右部分升序
        {
            if (target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    assert(4 == search(nums, 0));
    assert(-1 == search(nums, 3));
}