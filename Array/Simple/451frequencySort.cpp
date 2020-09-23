/*将字符串中字符按出现频率降序排列*/
#include <string>
#include <iostream>
#include <cassert>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string frequencySort(string s)
{
    unordered_map<char, int> ump;
    for (auto c : s)
        ++ump[c];
    vector<pair<char, int>> vec;
    for (auto m : ump)
        vec.push_back(m);
    sort(vec.begin(), vec.end(),[](const pair<char, int> &p1, const pair<char, int> &p2) 
    { return p1.second > p2.second; });
    string res;
    for (const auto &v : vec)
        res += string(v.second, v.first);
    return res;
}
//优先队列
string frequencySort_priorqueue(string s)
{
    unordered_map<char, int> ump;
    for (const auto &c : s)
        ump[c]++;
    priority_queue<pair<int, int>> pq;
    for (const auto &m : ump)
        pq.push({m.second, m.first});
    string res;
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        res.append(t.first, t.second);
    }
    return res;
}

//lambda自定义排序
string frequencySort_lambda(string s)
{
    unordered_map<char, int> ump;
    for (const auto &c : s)
        ump[c]++;
    sort(s.begin(), s.end(), [&](char &a, char &b) 
        { return (ump[a] > ump[b] || (ump[a] == ump[b] && a < b)); });
    return s;
}
//数组下标索引
string frequencySort_arr(string s)
{
    unordered_map<char, int> ump;
    for (const auto &c : s)
        ump[c]++;
    vector<string> vec(s.size() + 1);
    string res;
    for (const auto &m : ump)
        vec[m.second].append(m.second, m.first);
    for (int i = s.size(); i > 0; --i)
    {
        if (!vec[i].empty())
            res.append(vec[i]);
    }
    return res;
}
int main()
{
    string res{"eert"};
    assert(res == frequencySort("tree"));
    string res1{"cccaaa"};
    //答案"aaaccc"也对，相同字符必须在一起
    assert(res1 == frequencySort("cccaaa") || "aaaccc" == frequencySort("cccaaa"));
}