/*仅包含0,1的矩阵，找出只包含1的最大矩阵，并返回其面积。*/
#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;
//以每列高度为长的最大面积
//单调递增栈
int largestRectangleArea(vector<int> &heights)
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
    { //当前元素较小，可计算以栈顶为高的矩形面积
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
//转化为84题
int maximalRectangle(vector<vector<char>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> heights(col, 0);
    int res = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == '1')
                heights[j] += 1;
            else
                heights[j] = 0;
        }
        res = max(res, largestRectangleArea(heights));
    }
    return res;
}

int main()
{
    vector<int> vi{3, 1, 3, 2, 2};
    cout << largestRectangleArea(vi) << endl;
}