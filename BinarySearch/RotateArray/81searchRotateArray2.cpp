/*升序数组在某点进行旋转，判断目标值是否存在于数组中，存在返回true,否则false，
数组可包含重复元素*/
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

bool search(vector<int> &nums, int target)
{
    if (nums.empty())
        return false;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[left] == nums[mid]) //10111情况，不能确定哪边有序,只能遍历
        {
            left++;
            continue;
        }
        if (nums[left] < nums[mid])//左半边有序
        {
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    assert(search(nums, 0));
    assert(!search(nums, 3));
}