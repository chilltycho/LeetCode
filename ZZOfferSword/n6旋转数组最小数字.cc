/**
 * 输入非递减排序的数组一个旋转，输出旋转数组最小元素
*/
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
/*[3,4,5,1,2]此时a[mid]>a[left]但最小元素在右边  a[mid]>a[right]
  [1,2,3,4,5]此时a[mid]>a[left]但最小元素在左边  a[mid]<a[right]*/
int findMin_1(vector<int> &nums)
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
        else if(nums[mid]==nums[right])
            --right;
        else
            right = mid;
    }
    return nums[left];
}