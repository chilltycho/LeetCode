#include <vector>
#include <iostream>
using namespace std;
int binarySearch(vector<int> &nums, int target)
{
    int len = nums.size();
    if (len == 0)
        return -1; //未找到
    int left = 0;
    int right = len - 1;
    while (left <= right)//注意一个元素情况
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int binarySearch_2(vector<int> &nums, int left, int right, int target)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            return binarySearch_2(nums, mid + 1, right, target);
        else
            return binarySearch_2(nums, left, mid - 1, target);
    }
    return -1;
}

int main()
{
    vector<int> nums{-1, 0, 3, 5, 9, 12};
    cout << binarySearch_2(nums, 0, nums.size() - 1, 9);
}