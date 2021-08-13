/*给定一个只包含数字的字符串，复原它并返回所有可能的IP地址格式
输入：25525511135
输出：["255.255.11.135","255.255.111.35"]*/
#include <vector>
#include <iostream>
using namespace std;

vector<string> ans;
vector<string> temp;

void dfs_1(string &s, int start)
{
    if (start == s.size() && temp.size() == 4)
    {
        auto str = temp[0];
        for (int i = 1; i < temp.size(); ++i)
            str += "." + temp[i];
        ans.push_back(str);
        return;
    }
    if (start >= s.size())
        return;
    for (int len = 1; len <= 3; ++len)
    {
        if (len != 1 && s[start] == '0')
            return;
        string str = s.substr(start, len);
        if (len == 3 && atoi(str.c_str()) > 255)
            return;
        temp.push_back(str);
        dfs_1(s, start + len);
        temp.pop_back();
    }
}
vector<string> restoreIpAddresses_1(string s)
{
    int len = s.size();
    if (len < 4 || len > 12) //字符串长度小于4或大于12，一定不能凑出合法ip
        return ans;
    dfs_1(s, 0);
    return ans;
}

int main()
{
    string s = "25525511135";
    auto res = restoreIpAddresses_1(s);
    for (auto c : res)
        cout << c << ' ';
}