//在数组中两个数字，若前面大于后面，则组成逆序对，求数组中逆序对总数
#include <vector>
#include <iostream>
using namespace std;
//nums[left,mid]和nums[mid+1,right]均有序
int mergeAndCount(vector<int> &nums, int left, int mid, int right, vector<int> &temp)
{
    for (int i = left; i <= right; i++)
        temp[i] = nums[i];
    int l = left;
    int r = mid + 1;
    int count = 0;
    for (int k = left; k <= right; k++)
    {
        if (l == mid + 1)
        {
            nums[k] = temp[r];
            r++;
        }
        else if (r == right + 1)
        {
            nums[k] = temp[l];
            l++;
        }
        else if (temp[l] <= temp[r])
        {
            nums[k] = temp[l];
            l++;
        }
        else //前面大于后面，计算逆序对
        {
            nums[k] = temp[r];
            r++;
            count += (mid - l + 1);
        }
    }
    return count;
}

int reversePairs_help(vector<int> &nums, int left, int right, vector<int> &temp)
{
    if (left == right)
        return 0;
    int mid = left + (right - left) / 2;
    int leftPairs = reversePairs_help(nums, left, mid, temp);
    int rightPairs = reversePairs_help(nums, mid + 1, right, temp);
    if (nums[mid] <= nums[mid + 1]) //数组已经有序
        return leftPairs + rightPairs;
    int crossPairs = mergeAndCount(nums, left, mid, right, temp);
    return leftPairs + rightPairs + crossPairs;
}

int reversePairs(vector<int> &nums)
{
    auto len = nums.size();
    if (len < 2)
        return 0;
    vector<int> nums_copy = nums;
    vector<int> temp(len, 0);
    return reversePairs_help(nums_copy, 0, len - 1, temp);
}

int main()
{
    vector<int> nums{7, 5, 6, 4};
    cout << reversePairs(nums);
}