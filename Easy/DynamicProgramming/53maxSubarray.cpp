#include<vector>
#include<iostream>
using namespace std;
/*
用ai表示nums[i],f(i)表示以i结尾的连续子数组的最大和，则答案为max{f(i)}
考虑ai单独一段还是加入f(i-1)那一段，取决于ai和f(i-1)+ai的大小。
动态规划转移方程f(i)=max(f(i-1)+ai,ai)
*/
int maxSubArray(vector<int>& nums)
{
    int pre=0,maxAns=nums[0];
    for(const auto &x:nums)
    {
        pre=max(pre+x,x);
        maxAns=max(maxAns,pre);
    }
    return maxAns;
}