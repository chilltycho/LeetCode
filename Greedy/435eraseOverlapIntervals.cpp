//给定区间集合,找到需要移除区间最小数量,使剩余区间互不重叠
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.size() < 2)
        return 0;
    int res = 0;
    sort(intervals.begin(), intervals.end()); //按区间起点排序
    for (int i = 0; i < intervals.size() - 1; i++)
    {
        if (intervals[i][1] > intervals[i + 1][0]) //前一区间终点大于后一区间起点
        {
            res++;
            intervals[i + 1][1] = min(intervals[i][1], intervals[i + 1][1]);
        }
    }
    return res;
}

//贪心:按起点排序,选择结尾最早的,后面才能接上更多的区间
//若两个区间有重叠,应保留结尾早的
int eraseOverlapIntervals_greed(vector<vector<int>> &intervals)
{
    if (intervals.size() < 2)
        return 0;
    int res = 0;
    sort(intervals.begin(), intervals.end()); //按区间起点排序
    int end=intervals[0][1];
    for (int i=1;i<intervals.size();i++)
    {
        if (intervals[i][0]<end) //后一区间起点<前一区间终点
        {
            res++;
            end=min(end,intervals[i][1]);//保留终点小的
        }
        else
        {
            end=intervals[i][1];
        }
        
    }
    return res;
}


int main()
{
    vector<vector<int>> inte{{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(inte);       //移除{1,3}
    vector<vector<int>> inte1{{1, 2}, {2, 3}}; //无需移除
}