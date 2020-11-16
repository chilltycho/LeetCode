#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    for (int first = 0; first < len - 3; first++)
    {
        if (first > 0 && nums[first] == nums[first - 1])
            continue;
        for (int second = first + 1; second < len - 2; second++)
        {
            if (second > first + 1 && nums[second] == nums[second - 1])
                continue;
            int l = second + 1;
            int r = len - 1;
            while (l < r)
            {
                int sum = nums[first] + nums[second] + nums[l] + nums[r];
                if (sum == target)
                {
                    res.push_back(vector<int>{nums[first], nums[second], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r - 1])
                        r--;
                    l++;
                    r--;
                }
                if (sum > target)
                    r--;
                if (sum < target)
                    l++;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> vi{1, -2, -5, -4, -3, 3, 3, 5};
    auto res = fourSum(vi, -11);
    for (auto &c : res)
    {
        for (auto &cc : c)
            cout << cc << ' ';
        cout << endl;
    }
}