/*和谐数组：数组中最大元素与最小之间差别为1。给定一个整数数组，在子序列中找到最长和谐子序列长度
输入：[1,3,2,2,5,2,3,7]
输出：5  [3,2,2,2,3] 子序列不一定连续*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findLHS(vector<int> &nums) //超时
{
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 1; //第一个元素包含
        bool flag = false;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i == j)
                continue;
            if (nums[i] == nums[j])
                count++;
            if (nums[i] + 1 == nums[j])
            {
                count++;
                flag = true; //至少一个元素不同
            }
        }
        if (flag)
            res = max(count, res);
    }
    return res;
}

int findLHS_1(vector<int> &nums)
{
    unordered_map<int, int> um; //值,次数
    for (const auto &c : nums)
        um[c]++;
    int res = 0;
    for (const auto &c : nums)
    {
        if (um[c + 1] > 0)
            res = max(res, um[c + 1] + um[c]);
    }
    return res;
}

int main()
{
    vector<int> vi{1, 3, 2, 2, 5, 2, 3, 7};
    cout << findLHS_1(vi);
}