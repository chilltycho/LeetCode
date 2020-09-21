//相比153，存在可重复元素
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int findMin(vector<int> &nums)
{
    int len = nums.size();
    if (len == 1)
        return nums[0];
    int left = 0;
    int right = len - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else if (nums[mid] < nums[mid])
            right = mid;
        else
            right--;
    }
    return nums[left];
}

int main()
{
    vector<int> nums{1, 3, 5};
    assert(1 == findMin(nums));
    vector<int> nums1{2, 2, 2, 0, 1};
    assert(0 == findMin(nums1));
}