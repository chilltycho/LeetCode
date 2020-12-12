/*若连续数字之间差严格在正数和负数之间交替，则数字序列称为摆动序列。少于两个
元素的序列也是摆动序列。给定整数序列，返回作为摆动序列的最长子序列的长度*/
#include <vector>
#include <iostream>
using namespace std;
//最长子序列
int wiggleMaxLength(vector<int> &nums)
{
    if (nums.size() < 2)
        return nums.size();
    int n = nums.size();
    vector<int> up(n, 1), down(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            up[i] = max(up[i - 1], down[i - 1] + 1);
            down[i] = down[i - 1];
        }
        else if (nums[i] < nums[i - 1])
        {
            up[i] = up[i - 1];
            down[i] = max(down[i - 1], up[i - 1] + 1);
        }
        else
        {
            up[i] = up[i - 1];
            down[i] = down[i - 1];
        }
    }
    return max(up[n - 1], down[n - 1]);
}

int wiggleMaxLength_1(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return n;
    int up = 1, down = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
            up = max(up, down + 1);
        else if (nums[i] < nums[i - 1])
            down = max(up + 1, down);
    }
    return max(up, down);
}

int main()
{
}
