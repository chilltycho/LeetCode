/*给定无重叠的按区间起始端点排序的区间列表。插入新区间，确保有序不重叠*/
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> insert_1(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> res;
    int i = 0;
    int len = intervals.size();
    while (i < len && intervals[i][1] < newInterval[0]) // 新区间以左没重复的
    {
        res.push_back(intervals[i]);
        i++;
    }
    while (i < len && intervals[i][0] <= newInterval[1]) // 新区间有重复，不断合并给新区间
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);
    while (i < len)                        // 新区间以右没重复
    {
        res.push_back(intervals[i]);
        i++;
    }
    return res;
}

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int newL = newInterval[0];
    int newR = newInterval[1];
    bool placed = false;
    vector<vector<int>> merged;
    for (const auto &in : intervals)
    {
        if (in[0] > newR) //无交集
        {
            if (!placed) // 插入新区间时机
            {
                merged.push_back({newL, newR});
                placed = true;
            }
            merged.push_back(in);
        }
        else if (in[1] < newL) 
        {
            merged.push_back(in);
        }
        else //有交集，不断合并给新区间
        {
            newL = min(newL, in[0]);
            newR = max(newR, in[1]);
        }
    }
    if (!placed)
        merged.push_back({newL, newR});
    return merged;
}

int main()
{
}