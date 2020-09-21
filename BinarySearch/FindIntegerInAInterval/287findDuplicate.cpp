/*给定包含n+1个整数的数组nums,数字[1,n]，至少存在一个重复整数，假设只有一个，找出重复数
1.不能更改原数组 2.只能使用额外的O(1)空间*/
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
//[1，3，4，2，2,5]为例，中位数为3，遍历数组，统计小于等于3的整数，若不存在重复元素，最多3个。
int findDuplicate(vector<int> &nums)
{
    if (nums.empty())
        return -1;
    int len = nums.size();
    int left = 1;
    int right = len - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int cnt = 0;
        for (int num : nums)
        {
            if (num <= mid)
                cnt++;
        }
        if (cnt > mid)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    vector<int> nums{1, 3, 4, 2, 2};
    assert(2 == findDuplicate(nums));
    vector<int> nums1{3, 1, 3, 4, 2};
    assert(3 == findDuplicate(nums1));
}