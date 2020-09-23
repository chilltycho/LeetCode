/*给定区间集合，合并所有重叠的区间*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//按左端点排序，则可合并的区间一定连续。
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() == 0)
        return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (int i = 0; i < intervals.size(); i++)
    {
        int L = intervals[i][0], R = intervals[i][1];
        if (!merged.size() || merged.back()[1] < L)
            merged.push_back({L, R});
        else
            merged.back()[1] = max(merged.back()[1], R);
    }
    return merged;
}

int main()
{
    //区间[1,3]和[2,6]重叠，合并为[1,6]。返回[[1,6],[8,10],[15,18]]
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
}