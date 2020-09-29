//给定排序数组，原地删除重复出现元素，使得每个元素最多出现两次，返回移除后数组新长度
#include <vector>
#include <iostream>
using namespace std;

//允许k个重复元素
int removeDuplicates_1(vector<int> &nums, int k)
{
    if (nums.size() <= k)
        return nums.size();
    //定义[0,index]为修改后满足要求的数组区间，已经放入0..k-1共k个数
    int index = k - 1;
    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] != nums[index - k + 1])//此时可扩张结果数组
        {
            index++;
            nums[index] = nums[i];
        }
    }
    return index + 1;
}

int main()
{
    vector<int> nums1{1, 1, 1, 2, 2, 3};
    int res1 = removeDuplicates_1(nums1,2);
    for (int i = 0; i < res1; i++)
        cout << nums1[i] << ' ';
    cout << endl;
    vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};

    int res = removeDuplicates_1(nums,2);
    for (int i = 0; i < res; i++)
        cout << nums[i] << ' ';
}