/*判断nums中是否存在a+b+c=0*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
//暴力法，不重复遍历三元组
vector<vector<int>> threeSum_brute(vector<int> &nums)
{
    vector<vector<int>> res;
    int len = nums.size();
    if (len < 3)
        return res;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int first = 0; first < n - 2; first++)
    {
        //当和上次枚举元素相同时，跳过避免重复
        if (first > 0 && nums[first] == nums[first - 1])
            continue;
        for (int second = first + 1; second < n - 1; second++)
        {
            if (second > first + 1 && nums[second] == nums[second - 1])
                continue;
            for (int third = second + 1; third < n; third++)
            {
                if (third > second + 1 && nums[third] == nums[third - 1])
                    continue;
                if (nums[first] + nums[second] + nums[third] == 0)
                    res.push_back(vector<int>{nums[first], nums[second], nums[third]});
            }
        }
    }
    return res;
}

/*暴力法优化，固定前两重循环元素a,b则只有唯一元素a+b+c=0，二重循环往后枚举b'，则a+b+c'=0时，有c'<c。
* 故可从小到大枚举b，从大到小枚举c，第二重，第三重循环实际为并列关系*/
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    int len = nums.size();
    if (len < 3)
        return res;
    sort(nums.begin(), nums.end());
    for (int first = 0; first < len - 2; first++)
    {
        //第一个元素就大于0
        if (nums[first] > 0)
            break;
        if (first > 0 && nums[first] == nums[first - 1])
            continue; //不允许方案重复
        int second = first + 1;
        int third = len - 1;
        while (second < third)
        {
            int sum = nums[first] + nums[second] + nums[third];
            if (sum == 0)
            {
                res.push_back(vector<int>{nums[first], nums[second], nums[third]});
                while (second < third && nums[second + 1] == nums[second]) //第二个元素不能重复
                    second++;
                while (second < third && nums[third - 1] == nums[third]) //第三个元素不能重复
                    third--;
                second++;
                third--;
            }
            else if (sum > 0)
                third--;
            else
                second++;
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
    vector<int> nums1{1, 2, -2, -1};
    auto res1 = threeSum(nums1);
    for (auto c : res1)
    {
        for (auto cc : c)
            cout << cc << ' ';
        cout << endl;
    }
}