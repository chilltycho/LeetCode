/*给定R行C列的矩阵，单元格坐标为(r,c)
且0<=r<R,0<=c<C。给出坐标(r0,c0)，按曼哈顿距离排序*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//直接排序
vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
{
    vector<vector<int>> res;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            res.push_back(vector<int>{i, j});
    }
    sort(res.begin(), res.end(), [&r0, &c0](const vector<int> &a, const vector<int> &b) { return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0); });
    return res;
}
int dist(int r1, int c1, int r2, int c2)
{
    return abs(r1 - r2) + abs(c1 - c2);
}
//桶排序，遍历所有坐标，按距离大小分组，每组距离相同。按距离从小到达原则，遍历所有桶，并输出结果
vector<vector<int>> allCellsDistOrder_1(int R, int C, int r0, int c0)
{
    int maxDist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
    vector<vector<vector<int>>> bucket(maxDist + 1);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int d = dist(i, j, r0, c0);
            bucket[d].push_back(vector<int>{i, j});
        }
    }
    vector<vector<int>> res;
    for (int i = 0; i <= maxDist; i++)
        for (auto &it : bucket[i])
            res.push_back(it);
    return res;
}