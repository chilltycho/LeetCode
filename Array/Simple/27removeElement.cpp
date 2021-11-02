//给定数组nums和val,原地移除所有数值等于val的元素，返回移除后数组新长度
#include <vector>
#include <iostream>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    //[0,index]为有效元素
    int index = -1; //初始时无元素
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[++index] = nums[i];
        }
    }
    return index + 1;
}

int main()
{
    vector<int> nums{1, 2, 3, 1};
    int res = removeElement(nums, 1);
    for (int i = 0; i < res; i++)
        cout << nums[i] << ' ';
}