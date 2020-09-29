//给定排序数组，原地删除重复出现的元素，返回删除后数组新长度。
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

int removeDuplicates_1(vector<int> &nums)
{
    if (nums.size() < 2)
        return nums.size();
    //初始为[0,0]一个元素
    int index = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[index] != nums[i])
        {
            index++;
            nums[index] = nums[i];
        }
    }
    return index + 1;
}

int main()
{
    vector<int> nums{1, 1, 2}; //返回长度2，且前两个元素被修改为1，2
    int res = removeDuplicates_1(nums);
    for (int i = 0; i < res; i++)
        cout << nums[i] << ' ';
    cout << endl;
    vector<int> nums1{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}; //返回长度5，0,1,2,3,4
    int res1 = removeDuplicates_1(nums1);
    for (int i = 0; i < res1; i++)
        cout << nums1[i] << ' ';
    cout << endl;
}