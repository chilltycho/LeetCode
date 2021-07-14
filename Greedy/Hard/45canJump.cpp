#include<iostream>
#include<vector>
using namespace std;
int jump(vector<int> &nums)
{
    int tom = 0; // 当前覆盖最远下标
    int res = 0; // 走的最大步数
    int end = 0; // 下部覆盖最远距离下标
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        tom = max(i + nums[i], tom);
        if (i == end)
        {
            end = tom;
            ++res;
        }
    }
    return res;
}