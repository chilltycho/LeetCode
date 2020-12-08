/*给定无重叠的按区间起始端点排序的区间列表。插入新区间，确保有序不重叠*/
#include <vector>
#include <iostream>
using namespace std;

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
            if (!placed)
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
        else //有交集
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