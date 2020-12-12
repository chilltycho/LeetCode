//求高度数组能组成最大矩形面积
#include <vector>
#include <stack>
#include <cassert>
#include <climits>
using namespace std;
//以每列高度为长的最大面积
int largestRectangleArea(vector<int> &heights)
{
    int len = heights.size() - 1;
    if (len == 0)
        return 0;
    int res = 0;
    for (int i = 0; i <= len; i++)
    {
        int left = i;
        int curHeight = heights[i];
        while (left > 0 && heights[left - 1] >= curHeight)
            left--;
        int right = i;
        while (right < len - 1 && heights[right + 1] >= curHeight)
            right++;
        res = max(res, curHeight * (right - left + 1));
    }
    return res;
}

//单调递增栈
int largestRectangleArea_2(vector<int> &heights)
{
    if (heights.size() == 0)
        return 0;
    if (heights.size() == 1)
        return heights[0];
    int res = 0;
    heights.push_back(INT_MIN); //加哨兵，保证最后全部出栈，如果递增的话一直进栈
    int len = heights.size();
    stack<int> stk;
    for (int i = 0; i < len; i++)
    {   //当前元素较小，可计算以栈顶为高的矩形面积
        while (!stk.empty() && heights[i] < heights[stk.top()])
        {
            int top = stk.top();
            stk.pop();
            res = max(res, heights[top] * (stk.empty() ? i : (i - stk.top() - 1)));
        }
        stk.push(i);
    }
    return res;
}

int main()
{
    vector<int> vi{2, 1, 5, 6, 2, 3};
    assert(10 == largestRectangleArea_2(vi));
}