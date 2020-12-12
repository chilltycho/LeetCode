//给定n个非负数表示宽为1的柱子的高度,求下雨后能接多少雨水
#include <vector>
#include <stack>
#include <cassert>
#include<iostream>
using namespace std;
int getMax(vector<int> &height)
{
    int hm = 0;
    for (int i = 0; i < height.size(); i++)
        hm = max(hm, height[i]);
    return hm;
}
//按行求，求第i层的水
int trap_1(vector<int> &height)
{
    if (height.size() < 3)
        return 0;
    int sum = 0;
    int maxh = getMax(height);
    for (int i = 1; i <= maxh; i++) //从第1层开始
    {
        bool isStart = false;
        int temp = 0;
        for (int j = 0; j < height.size(); j++)
        {
            if (isStart && height[j] < i) //左边有墙，当前为凹
                temp++;
            if (height[j] >= i) //可作为墙
            {
                sum += temp;
                temp = 0;
                isStart = true;
            }
        }
    }
    return sum;
}

//按列求
int trap_2(vector<int> &height)
{
    if (height.size() < 3)
        return 0;
    int sum = 0;
    //两端列不会有水
    for (int i = 1; i < height.size() - 1; i++)
    {
        int max_left = 0; //左边最高
        for (int j = i - 1; j >= 0; j--)
            max_left = max(height[j], max_left);
        int max_right = 0; //右边最高
        for (int j = i + 1; j < height.size(); j++)
            max_right = max(height[j], max_right);
        int min_lr = min(max_left, max_right);
        if (min_lr > height[i]) //当前高度应小于两边较矮墙高度
            sum += (min_lr - height[i]);
    }
    return sum;
}

//提前保存每列左边最高，右边最高。动态规划
int trap_3(vector<int> &height)
{
    if (height.size() < 3)
        return 0;

    int len = height.size();
    int sum = 0;
    vector<int> max_left(len, 0);
    for (int i = 1; i < len; i++) //从左到右，求左边最高
        max_left[i] = max(max_left[i - 1], height[i - 1]);
    vector<int> max_right(len, 0);
    for (int i = len - 2; i >= 0; i--) //从右到左，求右边最高
        max_right[i] = max(max_right[i + 1], height[i + 1]);
    for (int i = 1; i < len - 1; i++)
    {
        int min_lr = min(max_left[i], max_right[i]);
        if (min_lr > height[i])
            sum += (min_lr - height[i]);
    }
    return sum;
}
//由于是从左往右遍历,故可即时更新左边最高
int trap_31(vector<int> &height)
{
    if (height.size() < 3)
        return 0;

    int len = height.size();
    int sum = 0;
    vector<int> max_right(len, 0);
    int max_left = 0;
    for (int i = len - 2; i >= 0; i--) //从右到左，求右边最高
        max_right[i] = max(max_right[i + 1], height[i + 1]);
    for (int i = 1; i < len - 1; i++)
    {
        max_left = min(max_left, height[i - 1]);
        int min_lr = min(max_left, max_right[i]);
        if (min_lr > height[i])
            sum += (min_lr - height[i]);
    }
    return sum;
}

int trap_4(vector<int> &height)
{
    if (height.size() < 3)
        return 0;

    int len = height.size();
    int sum = 0, max_left = height[0], max_right = height[len - 1];
    int left = 0;
    int right = len - 1; //右指针
    while (left <= right)
    {
        max_left = max(max_left, height[left]);
        max_right = max(max_right, height[right]);
        if (max_left < max_right)
        {
            sum += max_left - height[left];
            left++;
        }
        else
        {
            sum += max_right - height[right];
            right--;
        }
    }
    return sum;
}
/*每匹配一对括号，就计算两堵墙中的水。用栈保存每堵墙。
当前高度小于栈顶高度，有积水，入栈
当前高度大于栈顶高度，计算积水，入栈*/
int trap_6(vector<int> &height)
{
    if (height.size() < 3)
        return 0;
    int sum = 0;
    stack<int> si;
    for (int i = 0; i < height.size(); i++)
    {
        while (!si.empty() && height[i] > height[si.top()])
        {
            int h = height[si.top()];
            si.pop();
            if (si.empty())
                break;
            int dis = i - si.top() - 1;
            int minh = min(height[si.top()], height[i]);
            sum += dis * (minh - h);
        }
        si.push(i);
    }
    return sum;
}
int main()
{
    vector<int> vi{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<<trap_6(vi);
}