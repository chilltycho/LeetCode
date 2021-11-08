/*给定一个只包含数字的字符串，复原它并返回所有可能的IP地址格式
输入：25525511135
输出：["255.255.11.135","255.255.111.35"]*/
#include <vector>
#include <iostream>
using namespace std;

vector<string> path;
vector<string> res;
void dfs(string &s, int start)
{
    if (start == s.size() && path.size() == 4)
    {
        auto str = path[0];
        for (int i = 1; i < 4; ++i)
            str += "." + path[i];
        res.push_back(str);
        return;
    }
    if (start >= s.size())
        return;
    for (int len = 1; len <= 3; ++len)
    {
        if (len != 1 && s[start] == '0')
            return;
        auto str = s.substr(start, len);
        if (stoi(str) > 255)
            return;
        path.push_back(str);
        dfs(s, start + len);
        path.pop_back();
    }
}
vector<string> restoreIpAddresses(string s)
{
    if (s.size() < 4 || s.size() > 12)
        return res;
    dfs(s, 0);
    return res;
}

int main()
{
    string s = "25525511135";
    auto res = restoreIpAddresses(s);
    for (auto c : res)
        cout << c << ' ';
}