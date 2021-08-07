#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
//给定字符串s，找到s中最长回文子串。

/*如果一个字符串头尾两个字符不相等，则字符串一定不是回文串
  如果一个字符串头尾两个字符相等，才有必要继续判断：
    如果里面子串是回文，整体是回文
    如果里面子串是回文，整体不是回文

dp[i][j]表示子串s[i,j]是否为回文 dp[i][j]=(s[i]==s[j])&&dp[i+1][j-1]
边界条件[i+1,j-1]不构成区间，即长度小于2。*/
// 时间复杂度O(n^2) 空间复杂度O(n^2)
string longestPalindrome(string s)
{
    if (s.size() < 2)
        return s;
    auto len = s.size();
    auto maxLen = 1;
    auto begin = 0;
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for (int i = 0; i < len; i++)
        dp[i][i] = true; //单个字符一定是回文
    for (int j = 1; j < len; j++)
    {
        for (int i = 0; i < j; i++)
        {
            if (s[i] != s[j])
                dp[i][j] = false;
            else
            {
                if (j - i < 3)
                    dp[i][j] = true;
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            if (dp[i][j] && j - i + 1 > maxLen)
            {
                maxLen = j - i + 1;
                begin = i;
            }
        }
    }
    return s.substr(begin, maxLen);
}

/*中心扩散法：遍历每个索引，以索引为中心，利用对称特点，往外扩散，看能扩散多远。
奇数回文串‘中心’是一个具体字符，如'aba'中心是'b'
偶数回文串‘中心’是空隙，'abba'*/
// 时间复杂度O(n^2) 空间复杂度O(1)
string centerSpred(string s, int l, int r) //若传入重合索引，长度为奇数。若传入相邻索引，长度为偶数
{
    int n = s.size();
    while (l >= 0 && r < n)
    {
        if (s[l] == s[r])
        {
            --l;
            ++r;
        }
        else
            break;
    }
    return s.substr(l + 1, r - l - 1);
}

string longestPalindrome_cen(string s)
{
    auto size = s.size();
    if (size < 2)
        return s;
    auto maxLen = 1;
    auto res = s.substr(0, 1);
    for (auto i = 0; i < size - 1; i++)
    {
        auto oddStr = centerSpred(s, i, i);
        auto evenStr = centerSpred(s, i, i + 1);
        auto maxStr = oddStr.size() > evenStr.size() ? oddStr : evenStr;
        if (maxStr.size() > maxLen)
        {
            maxLen = maxStr.size();
            res = maxStr;
        }
    }
    return res;
}

int main()
{
    string s1 = "babad";
    assert("bab" == longestPalindrome_cen(s1));
    string s2 = "cbbd";
    assert("bb" == longestPalindrome_cen(s2));
}