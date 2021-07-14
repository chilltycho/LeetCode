//给定非负整数数组,最初位于第一个位置,每个元素代表该位置可跳跃最大长度,判断能否达到最后一个位置
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;
//对任意位置y,只要存在位置x,x+nums[x]>=y,则位置y可到达
bool canJump(vector<int> &nums)
{
    int k = 0;// 最远距离
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > k)// 不能到达i
            return false;
        k = max(k, i + nums[i]);
    }
    return true;
}

int main()
{
    vector<int> vi{2, 3, 1, 1, 4};
    assert(canJump(vi)); //先跳1步,从0到1,再从1到3到达最后一个位置
    vector<int> vi1{3, 2, 1, 0, 4};
    assert(!canJump(vi1)); //无论如何总会到达索引3
}