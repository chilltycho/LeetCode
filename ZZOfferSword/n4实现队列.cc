#include <iostream>
#include <stack>
using namespace std;

stack<int> s1; //加入队尾
stack<int> s2; //实现倒序

void push(int node)
{
    s1.push(node);
}

int pop()
{
    if (!s2.empty())
    {
        int res = s2.top();
        s2.pop();
        return res;
    }
    if (s1.empty())
        return -1;
    else
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int res = s2.top();
        s2.pop();
        return res;
    }
}