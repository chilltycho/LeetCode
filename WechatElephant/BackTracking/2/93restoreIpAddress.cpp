/*给定一个只包含数字的字符串，复原它并返回所有可能的IP地址格式
输入：25525511135
输出：["255.255.11.135","255.255.111.35"]*/
#include <vector>
#include <iostream>
using namespace std;

vector<string> res;

int judgeIfIpSegment(string s, int left, int right)
{
    int len = right - left + 1;
    if (len > 1 && s[left] == '0')
        return -1;
    int res = 0;
    for (int i = left; i <= right; i++)
        res = res * 10 + (s[i] - '0');
    if (res > 255)
        return -1;
    return res;
}

void dfs(string s, int len, int split, int begin, vector<string> &path)
{
    if (begin == len)
    {
        if (split == 4)
            for (int i = 0; i < 4; i++)
            {
                res[i] += path[i] + ".";
            }
        return;
    }
    if (len - begin < (4 - split) || len - begin > 3 * (4 - split))
        return;
    for (int i = 0; i < 3; i++)
    {
        if (begin + i >= len)
            break;
        int ipSegment = judgeIfIpSegment(s, begin, begin + i);
        if (ipSegment != -1)
        {
            path.push_back(to_string(ipSegment));
            dfs(s, len, split + 1, begin + 1, path);
            path.pop_back();
        }
    }
}

vector<string> restoreIpAddresses(string s)
{
    int len = s.size();
    if (len < 4 || len > 12)
        return res;
    vector<string> s(4);
    vector<string> path;
    int splitTimes = 0;
    dfs(s, len, splitTimes, 0, path);
    return res;
}

int main()
{
    string s = "25525511135";
    auto res = restoreIpAddresses(s);
    for (auto c : res)
        cout << c << ' ';
}