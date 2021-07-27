// 找到数组中和为k的连续的子数组的个数
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// 构建前缀和数组，快速计算区间和，超时
int subarraySum(vector<int> &nums, int k)
{
    vector<int> preSum(nums.size() + 1, 0);
    preSum[0] = 0;
    for (int i = 0; i < nums.size(); ++i)
        preSum[i + 1] = preSum[i] + nums[i];
    int res = 0;
    for (int l = 0; l < nums.size(); ++l)
    {
        for (int r = l; r < nums.size(); ++r)
            if (preSum[r + 1] - preSum[l] == k)
                ++res;
    }
    return res;
}

// 前缀和+哈希表优化
int subarraySum_1(vector<int> &nums, int k)
{
    unordered_map<int, int> preSumFreq;
    preSumFreq[0] = 1; // 下标为0的元素，前缀和为0，个数为1
    int preSum = 0;
    int count = 0;
    for (auto c : nums)
    {
        preSum += c;
        if (preSumFreq.count(preSum - k)) // 如果有前缀和为presum-k, 则有连续数组和为k
            count += preSumFreq[preSum - k];
        ++preSumFreq[preSum];
    }
    return count;
}

int main()
{
    vector<int> nums{1, 1, 1};
    cout << subarraySum(nums, 2); //[1,1], [1,1]
}