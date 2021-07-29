/*给定字符串s，将s分割为子串，使每个子串都是回文串*/
#include <vector>
#include <iostream>
using namespace std;
vector<vector<string>> res;
vector<string> path;
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

void dfs(string s, int start, int len)
{
    if (start == len)
    {
        res.push_back(path);
        return;
    }
    for (int i = start; i < len; i++)
    {
        if (!isPalindrome(s, start, i))
            continue;
        path.push_back(s.substr(start, i + 1 - start));
        dfs(s, i + 1, len);
        path.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    int len = s.size();
    if (len == 0)
        return res;
    dfs(s, 0, len);
    return res;
}

void dfs_1(string s, int start, int len, vector<vector<bool>> &dp)
{
    if (start == len)
    {
        res.push_back(path);
        return;
    }
    for (int i = start; i < len; i++)
    {
        if (!dp[start][i])
            continue;
        path.push_back(s.substr(start, i + 1 - start));
        dfs_1(s, i + 1, len, dp);
        path.pop_back();
    }
}

// 中心扩展法先判断子串是否回文
void prePro(string &s, int l, int r, vector<vector<bool>> &dp)
{
    while (l >= 0 && r < s.size() && s[l] == s[r])
    {
        dp[l][r] = true;
        --l, ++r;
    }
}
vector<vector<string>> partition_1(string s)
{
    int len = s.size();
    if (len == 0)
        return res;
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for (int i = 0; i < len; ++i)
    {
        prePro(s, i, i, dp);
        prePro(s, i, i + 1, dp);
    }
    dfs_1(s, 0, len, dp);
    return res;
}

int main()
{
    string s = "aab";
    partition_1(s);
    for (auto v : res)
    {
        for (auto s : v)
            cout << s << ' ';
        cout << endl;
    }
}