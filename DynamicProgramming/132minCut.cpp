/*给定字符串s，将s分割为子串，每个子串都是回文串。返回最少分割次数*/
#include <vector>
#include <iostream>
using namespace std;

bool isPalindrome(string s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

/*dp[i]:表示前缀s[0:i]分割回文子串所需最小分割次数。
dp[i] = 0 if s[0:i]回文。
s[0:i]不是回文，尝试分割，枚举分割边界j, s[j+1,i]不是回文，尝试下一边界，s[j+1,i]是回文。dp[i]=dp[j]+1
dp[i]=min(dp[j]+1 for j in range(i) if s[j+1,i]是回文。
如果s[0:i]回文，dp[i]=0
如果s[0:i]不是回文，由于求最小分割数，从最左边开始s[j,i]看是否为回文。*/
int minCut(string s)
{
    int len = s.size();
    if (len < 2)
        return 0;
    vector<int> dp(len);
    for (int i = 0; i < len; i++)
        dp[i] = i;

    for (int i = 1; i < len; i++)
    {
        if (isPalindrome(s, 0, i))
        {
            dp[i] = 0;
            continue;
        }
        for (int j = 0; j < i; j++)
        {
            if (isPalindrome(s, j + 1, i))
                dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    return dp[len - 1];
}

//优化，先判断子串是否为回文
int minCut_1(string s)
{
    int len = s.size();
    if (len < 2)
        return 0;
    vector<int> dp(len);
    for (int i = 0; i < len; i++)
        dp[i] = i;

    vector<vector<bool>> isPali(len, vector<bool>(len,false));
    for (int r = 0; r < len; r++)
    {
        for (int l = 0; l <= r; l++)
        {
            if (s[l] == s[r] && (r - l <= 2 || isPali[l + 1][r - 1]))
                isPali[l][r] = true;
        }
    }

    for (int i = 1; i < len; i++)
    {
        if (isPali[0][i])
        {
            dp[i] = 0;
            continue;
        }
        for (int j = 0; j < i; j++)
        {
            if (isPali[j + 1][i])
                dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    return dp[len - 1];
}
