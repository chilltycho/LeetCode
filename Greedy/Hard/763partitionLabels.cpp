#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
vector<int> partitionLabels(string s)
{
    unordered_map<char, pair<int, int>> um;
    for (int i = 0; i < s.size(); ++i)
    {
        if (!um.count(s[i]))
            um[s[i]].first = i;
        else
            um[s[i]].second = i;
    }
    vector<pair<int, int>> vp;
    for (auto c : um)
        vp.push_back(c.second);
    sort(vp.begin(), vp.end(), [](pair<int, int> &p1, pair<int, int> &p2)
         { return p1.first < p2.first; });
    vector<pair<int, int>> res;
    res.push_back(vp[0]);
    for (int i = 1; i < vp.size(); ++i)
    {
        if (vp[i].first > vp[i].second)
            vp[i].second = vp[i].first;
        if (vp[i].first < res.back().second)
            res.back().second = max(vp[i].second, res.back().second);
        else
            res.push_back(vp[i]);
    }
    vector<int> ans;
    for (auto c : res)
        ans.push_back(c.second - c.first + 1);
    return ans;
}

vector<int> partitionLables_1(string s)
{
    int last[26];
    int sz = s.size();
    for (int i = 0; i < sz; ++i)
        last[s[i] - 'a'] = i;
    vector<int> res;
    int start = 0, end = 0;
    for (int i = 0; i < sz; ++i)
    {
        end = max(end, last[s[i] - 'a']);
        if (i == end)
        {
            res.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return res;
}

int main()
{
    auto res = partitionLabels("ababcbacadefegdehijhklij");
    for (auto c : res)
        cout << c << ' ';
}