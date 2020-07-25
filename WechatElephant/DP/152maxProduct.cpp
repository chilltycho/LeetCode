#include <iostream>
#include <vector>
using namespace std;
int maxProduct(vector<int> &nums)
{
    vector<int> maxF(nums), minF(nums);
    int res = 0;
    for (int i = 1; i < nums.size(); ++i)
    {
        maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
        minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
        res = max(res, maxF[i]);
    }
    return res;
}
int maxProduct_1(vector<int> &nums)
{
    int maxF = nums[0], minF = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        int mx = maxF, mn = minF;
        maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
        minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
        ans = max(maxF, ans);
    }
    return ans;
}

int maxProduct_2(vector<int> &nums)
{
    int res = INT_MIN, imax = 1, imin = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            int tmp = imax;
            imax = imin;
            imin = tmp;
        }
        imax = max(imax * nums[i], nums[i]);
        imin = min(imin * nums[i], nums[i]);
        res = max(res, imax);
    }
    return res;
}

int main()
{
    vector<int> vi{2, 3, 0, -2, -4};
    cout << maxProduct(vi);
}