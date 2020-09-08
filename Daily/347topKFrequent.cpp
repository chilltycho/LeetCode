#include <vector>
#include <iostream>
#include <unordered_map>
#include <cassert>
#include <queue>
using namespace std;
bool cmp(pair<int, int> &m, pair<int, int> &n)
{
    return m.second > n.second;
}
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> occurrences;
    for (auto &v : nums)
        occurrences[v]++;
    //保存元素类型，用于存储元素的容器类型，排序根据
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
    for (auto &c : occurrences)
    {
        if (q.size() == k)
        {
            if (q.top().second < c.second)
            {
                q.pop();
                q.emplace(c);
            }
        }
        else
        {
            q.emplace(c);
        }
    }
    vector<int> ret;
    while (!q.empty())
    {
        ret.emplace_back(q.top().first);
        q.pop();
    }
    return ret;
}

int main()
{
    //给定非空整数数组，返回其中出现频率前k高的元素。假定k总合理
    vector<int> nums{1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> r1 = topKFrequent(nums, 2);
    for (auto c : r1)
        cout << c << endl;
}