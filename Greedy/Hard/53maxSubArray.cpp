#include<algorithm>
#include <vector>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    vector<int> dp(nums.size());
    dp[0]=nums[0];
    for(int i=1;i<nums.size();++i)
    {
        dp[i]=max(dp[i-1],0)+nums[i];
    }
    return *max_element(dp.begin(),dp.end());
}