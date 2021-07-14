/*用最少数量箭引爆气球,区间表示气球直径范围*/
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

int findMinArrowShots(vector<vector<int>> &points)
{
    if (points.size() < 2)
        return points.size();
    sort(points.begin(), points.end());
    int res = 1;
    int curEnd = points[0][1];
    for (size_t i = 1; i < points.size(); i++)
    {
        if (points[i][0] > curEnd) //必须增加箭情况
        {
            curEnd = points[i][1];
            res++;
        }
        else
            curEnd = min(curEnd, points[i][1]);
    }
    return res;
}

int main()
{
    vector<vector<int>> vi{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    assert(2 == findMinArrowShots(vi));
}