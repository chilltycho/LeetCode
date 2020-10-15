//按升序排序的数组在某点旋转，找出最小元素，不存在重复元素
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

int findMin(vector<int> &nums)
{
    int len = nums.size();
    if (len == 1)
        return nums[0];
    int left = 0;
    int right = len - 1;
    if (nums[right] > nums[left]) //本身已经有序
        return nums[left];
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) //证明从nums[mid]处旋转
            return nums[mid + 1];
        if (nums[mid - 1] > nums[mid])
            return nums[mid];
        //继续寻找转折点
        if (nums[mid] > nums[0])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; //永远不会执行
}
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
        else
            right = mid;
    }
    return nums[left];
}

int main()
{
    vector<int> nums{3, 4, 5, 1, 2};
    assert(1 == findMin(nums));
    vector<int> nums1{4, 5, 6, 7, 0, 1, 2};
    assert(0 == findMin(nums1));
}