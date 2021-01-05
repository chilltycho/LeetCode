/*给定字符串s，将s分割为子串，使每个子串都是回文串*/
#include <vector>
#include <iostream>
using namespace std;
vector<vector<string>> res;
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

void dfs(string s, int start, int len, vector<string> &path)
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
        dfs(s, i + 1, len, path);
        path.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    int len = s.size();
    if (len == 0)
        return res;
    vector<string> path;
    dfs(s, 0, len, path);
    return res;
}

int main()
{
    string s = "aab";
    partition(s);
    for (auto v : res)
    {
        for (auto s : v)
            cout << s << ' ';
        cout << endl;
    }
}