/*给定一个只包含数字的字符串，复原它并返回所有可能的IP地址格式
输入：25525511135
输出：["255.255.11.135","255.255.111.35"]*/
#include <vector>
#include <iostream>
using namespace std;

vector<string> res;

int judgeIfIpSegment(string s, int left, int right) //判断片段是否合法，0-255
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
        if (split == 4) //分成4段
        {
            string tempres = "";
            for (int i = 0; i < 4; i++)
            {
                tempres += path[i] + ".";
            }
            tempres.pop_back();
            res.push_back(tempres);
        }
        return;
    }
    if (len - begin < (4 - split) || len - begin > 3 * (4 - split)) //len-begin为剩余长度，看剩下的够不够
        return;
    for (int i = 0; i < 3; i++) //每个节点可截取1、2、3位
    {
        if (begin + i >= len)
            break;
        int ipSegment = judgeIfIpSegment(s, begin, begin + i);
        if (ipSegment != -1)
        {
            path.push_back(to_string(ipSegment));
            dfs(s, len, split + 1, begin + i + 1, path);
            path.pop_back();
        }
    }
}

vector<string> restoreIpAddresses(string s)
{
    int len = s.size();
    if (len < 4 || len > 12) //字符串长度小于4或大于12，一定不能凑出合法ip
        return res;
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