#include<queue>
#include<vector>
using namespace std;

int get(int x)
{
    int res = 0;
    for (; x; x /= 10)
        res += x % 10;
    return res;
}
int movingCount(int threshold, int rows, int cols)
{
    int k = threshold, m = rows, n = cols;
    if (k <= 0)
        return 0;
    int res = 0;
    queue<pair<int, int>> mq;
    mq.push({0, 0});
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vis[0][0] = true;
    vector<vector<int>> moves{{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; //向下,向右
    while (!mq.empty())
    {
        // 每次进入队列的都合法
        res++;
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
        }
    }
    return res;
}









