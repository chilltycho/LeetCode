/*给定字符串s，去除字符串中重复的字母，且保证返回结果的字典序最小（不打乱相对顺序）*/
#include <iostream>
#include <vector>
using namespace std;
// 递增单调栈
string removeDuplicateLetters(string s)
{
    vector<int> vis(128), num(128);
    for (auto c : s)
        ++num[c];
    string stk;
    for (char c : s)
    {
        if (!vis[c])//c未遍历过
        {
            while (!stk.empty() && stk.back() > c)
            {
                if (num[stk.back() - 'a'] > 0)
                {
                    vis[stk.back() - 'a'] = 0;
                    stk.pop_back();
                }
                else
                {
                    break;
                }
            }
            vis[c - 'a'] = 1;
            stk.push_back(c);
        }
        num[c - 'a'] -= 1;//c重复，跳过
    }
    return stk;
}