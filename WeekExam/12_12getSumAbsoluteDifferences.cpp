/*给定非递减有序数组，返回result数组。result[i]=nums[i]与其他元素差的绝对值之和*/
#include <iostream>
#include <vector>
using namespace std;
/*对于位置i，左边部分位置j贡献为nums[i]-nums[j] 右边部分贡献nums[j]-nums[i]*/
vector<int> getSumAbsoluteDifferences(vector<int> &nums)
{
    int n = nums.size();
    vector<int> presum(n + 1, 0);
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        presum[i + 1] += presum[i] + nums[i];
    for (int i = 0; i < n; i++)
    {
        int x = i, y = n - x - 1;
        int leftSum = presum[i];
        int rightSum = presum[n] - presum[i + 1];
        int lpart = x * nums[i] - leftSum;
        int rpart = rightSum - y * nums[i];
        res[i] = lpart + rpart;
    }
    return res;
}