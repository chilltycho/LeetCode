//机器人运动范围,m行n列方格,不能进入行坐标+列坐标数位之和>k的方格,求能到达多少格子
#include <queue>
#include <vector>
#include <cassert>
using namespace std;
int get(int x)
{
    int res = 0;
    for (; x; x /= 10)
        res += x % 10;
    return res;
}

int movingCount(int m, int n, int k)
{
    if (k == 0)
        return 1;
    int res = 1;
    queue<pair<int, int>> mq;
    mq.push({0, 0});
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vector<vector<int>> moves{{0, 1}, {1, 0}}; //向下,向右
    while (!mq.empty())
    {
        auto pos = mq.front();
        mq.pop();
        for (const auto &move : moves)
        {
            int x = pos.first + move[0];
            int y = pos.second + move[1];
            if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y] || get(x) + get(y) > k)
                continue;
            vis[x][y] = true;
            mq.push({x, y});
            res++;
        }
    }
    return res;
}

int main()
{
    assert(3 == movingCount(2, 3, 1));
    assert(1 == movingCount(3, 1, 0));
}