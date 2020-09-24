/*判断nums中是否存在a+b+c=0*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    int len = nums.size();
    if (len < 3)
        return res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < len - 2; i++)
    {
        //第一个元素就大于0
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue; //不允许方案重复
        int left = i + 1;
        int right = len - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                while (left < right && nums[left + 1] == nums[left])
                    left++;
                while (left < right && nums[right - 1] == nums[right])
                    right--;
                left++;
                right--;
            }
            else if (sum > 0)
                right--;
            else
                left++;
        }
    }
    return res;
}

int main()
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    /*[
        [-1,0,1],
        [-1,-1,2]
      ]*/
    auto res = threeSum(nums);
    for (auto c : res)
    {
        for (auto cc : c)
            cout << cc << ' ';
        cout << endl;
    }
    cout << endl;
    vector<int> nums1{0, 0, 0, 0};
    auto res1 = threeSum(nums1);
    for (auto c : res1)
    {
        for (auto cc : c)
            cout << cc << ' ';
        cout << endl;
    }
}