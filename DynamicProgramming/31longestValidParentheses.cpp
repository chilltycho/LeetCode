//求最长包含有效括号的子串的长度
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
//动态规划，以下标i结尾的合法括号长度
int longestValidParenttheses(string s)
{
    int res = 0;
    vector<int> dp(s.size(), 0);
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] == '(')
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') //...))的情况
                dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            res = max(dp[i], res);
        }
    }
    return res;
}