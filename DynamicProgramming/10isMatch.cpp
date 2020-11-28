//给定字符串s和字符规律p,实现支持'.'和'*'的正则表达式匹配
//'.'匹配任意单个字符,'*'匹配零个或多个前一个元素
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
/*动态规划:每次从p取一个字符或字符+*组合.
f[i][j]:s(0,i-1)和p(0,j-1)是否匹配.
从左往右,需考虑后面是否接*,分析麻烦
从右往左,*前肯定有字符*/
bool isMatch(string s, string p)
{
    if (p[0] == '*')//应确保*前有字符
        return false;
    if (s.empty() && p.empty())
        return true;
    if (p.empty() && (!s.empty()))
        return false;
    auto sLen = s.size();
    auto pLen = p.size();
    vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));
    dp[0][0] = true;//两个空字符串
    for (size_t j = 1; j < pLen + 1; j++)//s为空,p不为空
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 2];

    for (size_t i = 1; i < sLen + 1; i++)
    {
        for (size_t j = 1; j < pLen + 1; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.')//最后字符匹配
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')//不匹配，但有*号
            {
                if (s[i - 1] == p[j - 2] || p[j - 2] == '.')//*号可让消失，重复1次，重复多次
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 2];
            }
        }
    }
    return dp[sLen][pLen];
}

int main()
{
    assert(!isMatch("aa", "a"));
    assert(isMatch("aa", "a*"));
    assert(isMatch("ab", ".b"));

    assert(isMatch("aab", "c*a*b")); //a与c不匹配,需看c后面是否接*
    assert(isMatch("ab", ".*"));     //.*可与任意2个字符匹配
}