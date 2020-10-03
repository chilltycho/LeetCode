/*给定平面上n对不同的点，回旋镖是由点表示的元组[i,j,k]其中i和j之间的距离和i和k之间距离相等。
找到所有回旋镖的数量，可假设n最大为500，所有点的坐标在闭区间[-10000,10000]中
输入：[[0,0],[1,0],[2,0]]
输出：2  [[1,0],[0,0],[2,0]] 和[[1,0],[2,0],[0,0]]*/
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>
#include <unordered_map>
using namespace std;

int distance(vector<int> &p1, vector<int> &p2)
{
    return pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2);
}

int numberOfBoomeranges(vector<vector<int>> &points)
{
    int points_size = points.size();
    unordered_map<int, int> count; //距离，距离出现次数
    int dis, ans = 0;
    for (int i = 0; i < points_size; i++)
    {
        count.clear();
        for (int j = 0; j < points_size; j++)
        {
            if (i == j)
                continue;
            dis = distance(points[i], points[j]);
            ++count[dis];
        }
        for (auto c : count)
            if (c.second >= 2)
                ans += c.second * (c.second - 1); //排列组合，C_n^2=n*(n-1)
    }
    return ans;
}

int main()
{
    vector<vector<int>> vvi{{0, 0}, {1, 0}, {2, 0}};
    assert(2 == numberOfBoomeranges(vvi));
}