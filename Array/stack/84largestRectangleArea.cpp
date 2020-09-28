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
    for (int i = 0; i < len; i++)
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
//单调递增栈，只存入比栈顶高的下标值，否则一直弹出栈
int largestRectangleArea_1(vector<int> &heights)
{
    int len = heights.size() - 1;
    if (len == 0)
        return 0;
    if (len == 1)
        return heights[0];
    int res = 0;
    stack<int> si;
    for (int i = 0; i < len; i++)
    {
        //当前高度较小，则可计算栈中较高高度面积
        while (!si.empty() && heights[i] < heights[si.top()])
        {
            int curHeight = heights[si.top()];
            while (!si.empty() && heights[si.top()] == curHeight)
            {
                si.pop();
            }
            int curWidth;
            if (si.empty())
                curWidth = 1;
            else
            {
                curWidth = i - si.top() - 1;
            }
            res = max(res, curHeight * curWidth);
        }
        si.push(i);
    }
    while (!si.empty())
    {
        int curHeight = heights[si.top()];
        while (!si.empty() && heights[si.top()] == curHeight)
            si.pop();
        int curWidth;
        if (si.empty())
            curWidth = len;
        else
            curWidth = len - si.top() - 1;
        res = max(res, curHeight * curWidth);
    }
    return res;
}

//加哨兵
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
    {
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