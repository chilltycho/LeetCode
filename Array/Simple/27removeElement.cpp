//给定数组nums和val,原地移除所有数值等于val的元素，返回移除后数组新长度
#include <vector>
#include <iostream>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int i = 0;
    int n = nums.size();
    while (i < n)
    {
        if (nums[i] == val)
        {
            nums[i] = nums[n - 1];
            n--;
        }
        else
            i++;
    }
    return n;
}

int removeElement_1(vector<int> &nums, int val)
{
    int ans = 0;
    for (const auto c : nums)
    {
        if (c != val)
        {
            nums[ans] = c;
            ans++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums{1, 2, 3, 1};
    int res = removeElement(nums, 1);
    for (int i = 0; i < res; i++)
        cout << nums[i] << ' ';
}