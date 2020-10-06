//数组代表墙高度,求两堵墙,使得与x轴构成的容器可容纳最多的水
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;
//贪心思想:总是先固定容器宽度.高的墙往里走,只能让盛水越来越少,短的往里走,可能让水越来越多
int maxArea(vector<int> &height)
{
    int len = height.size();
    if (len < 2)
        return 0;
    int l = 0;
    int r = len - 1;
    int res = 0;
    while (l < r)
    {
        int area = (r - l) * min(height[l], height[r]);
        res = max(area, res);
        if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return res;
}

int main()
{
    vector<int> vi{1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(49 == maxArea(vi));
}