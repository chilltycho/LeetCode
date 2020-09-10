#include <iostream>
#include <vector>
using namespace std;
/*给定整数数组nums,找出数组中乘积最大的连续子数组，返回子数组对应乘积，[2,3,-2,4]：6*/

/*根据最大子序列和f_max(i)=max(f[i-1]*ai,ai)。但由于乘积应考虑负数，根据正负性进行分类讨论：
若当前位置为负数，希望前一个位置结尾某段的积为负，且该积绝对值很大。

fmin(i)表示以第i个元素结尾的乘积最小子数组的乘积
fmax[i]=max(fmax[i-1]*ai,fmin[i-1]*ai,ai)
fmin[i]=min(fmax[i-1]*ai,fmin[i-1]*ai,ai)
*/
int maxProduct(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    vector<int> maxF(nums), minF(nums);
    int res = nums[0];
    maxF[0] = nums[0];
    minF[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
        minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
        res = max(res, maxF[i]);
    }
    return res;
}
//优化空间，第i个状态仅和第i-1个状态相关。
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