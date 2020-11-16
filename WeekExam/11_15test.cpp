#include <vector>
#include <climits>
using namespace std;

int minOperations(vector<int> &nums, int x)
{
    int sum = 0;
    for (auto &c : nums)
        sum += c;
    int target = sum - x;
    int res = INT_MAX;
    int windowsum = 0;
    int len = nums.size();
    for (int l = 0, r = 0; r < len; r++)
    {
        windowsum += nums[r];
        while (l <= r && windowsum > target)
        {
            windowsum -= nums[l];
            l++;
        }
        if (windowsum == target)
        {
            res = min(res, len - (r - l + 1));
            windowsum -= nums[l];
            l++;
        }
    }
    if (res == INT_MAX)
        return -1;
    return res;
}