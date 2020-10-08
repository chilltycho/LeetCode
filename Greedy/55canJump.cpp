//给定非负整数数组,最初位于第一个位置,每个元素代表该位置可跳跃最大长度,判断能否达到最后一个位置
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;
//对任意位置y,只要存在位置x,x+nums[x]>=y,则位置y可到达
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int arrive_most = 0;
    for (int i = 0; i < n; i++)
    {
        if (i <= arrive_most)//保证能到达第i个位置
        {
            arrive_most = max(arrive_most, i + nums[i]);
            if (arrive_most >= n - 1)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<int> vi{2, 3, 1, 1, 4};
    assert(canJump(vi)); //先跳1步,从0到1,再从1到3到达最后一个位置
    vector<int> vi1{3, 2, 1, 0, 4};
    assert(!canJump(vi1)); //无论如何总会到达索引3
}