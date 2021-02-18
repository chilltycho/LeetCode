#include <climits>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int res = INT_MAX;
    int dis = INT_MAX;
    int len = nums.size();
    if (len < 3)
        return res;
    sort(nums.begin(), nums.end());
    for (int first = 0; first < len - 2; first++)
    {

        if (first > 0 && nums[first] == nums[first - 1])
            continue; //不允许方案重复
        int second = first + 1;
        int third = len - 1;
        while (second < third)
        {
            int sum = nums[first] + nums[second] + nums[third];
            int tdis = abs(target - sum);
            if (tdis < dis)
            {
                
            }
                res = sum;
            if (sum == target)
            {
                return target;
            }
            else if (sum > target)
                third--;
            else
                second++;
        }
    }
    return res;
}
