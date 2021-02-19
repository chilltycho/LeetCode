//给定按升序排列的数组，和目标值，找出给定目标值在数组中开始位置和结束位置
#include <vector>
#include <iostream>
using namespace std;

int findFirstPosition(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2; //向下取整
        if (nums[mid] == target)
            right = mid - 1; //不可直接返回，应继续向左找
        else if (nums[mid] < target)
            left = mid + 1; //继续向右找
        else
            right = mid - 1;
    }
    if (left != nums.size() && nums[left] == target)
        return left;
    return -1;
}

int findLastPosition(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            left = mid + 1; //应继续向右找
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int len = nums.size();
    if (len == 0)
        return vector<int>{-1, -1};
    int firstPosition = findFirstPosition(nums, target);
    if (firstPosition == -1)
        return vector<int>{-1, -1};
    int lastPosition = findLastPosition(nums, target);
    return vector<int>{firstPosition, lastPosition};
}

vector<int> searchRange_1(vector<int> &nums, int target)
{
    vector<int> res{-1, -1};
    if (nums.empty())
        return res;
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    if (nums[left] != target)
        return res;
    int i = left + 1;
    for (; i < nums.size(); i++)
        if (nums[i] != target)
            break;
    res[0] = left;
    res[1] = i - 1;
    return res;
}

int main()
{
    vector<int> nums{5, 7, 7, 8, 8, 10};

    auto res = searchRange(nums, 8);
    cout << res[0] << res[1];
}