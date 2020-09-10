#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
//找出一个海洋区域(0)，海洋区域离他最近的陆地(1)区域的距离最大。距离为曼哈顿距离：[x0,y0] [x1,y1]间距离|x0-x1|+|y0-y1|,若只有海洋或陆地，则返回-1

//以陆地为起点，向外bfs，可同时在为1的点bfs，称为多源bfs
bool inArea(const vector<vector<int>> &grid, int r, int c)
{
    return 0 <= r && r < grid.size() && 0 <= c && c < grid[0].size();
}

int maxDistance(vector<vector<int>> grid)
{
    int N = grid.size();
    deque<vector<int>> mq;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 1)
                mq.push_back({i, j});
        }
    }
    if (mq.empty() || mq.size() == N * N)
        return -1;
    vector<vector<int>> moves{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int distance = -1;//只有陆地或者海洋时，返回-1
    while (!mq.empty())
    {
        distance++; //由于每次总是x或y轴移动一次，所以每次距离加1
        int n = mq.size();
        for (int i = 0; i < n; i++)//层序
        {
            vector<int> node = mq.front();
            mq.pop_front();
            int r = node[0];
            int c = node[1];
            for (auto move : moves)
            {
                int r2 = r + move[0];
                int c2 = c + move[1];
                if (inArea(grid, r2, c2) && grid[r2][c2] == 0)
                {
                    grid[r2][c2] = 2;
                    mq.push_back({r2, c2});
                }
            }
        }
    }
    return distance;
}

//暴力法，对每个海洋区域计算距离
static constexpr int dx[4]{-1, 0, 1, 0}, dy[4]{0, 1, 0, -1};
static constexpr int MAX_N = 100 + 5;
struct Coordinate
{
    int x, y, step;
};
int n, m;
bool vis[MAX_N][MAX_N];

int findNearestLand(vector<vector<int>> &grid, int x, int y)
{
    memset(vis, 0, sizeof vis);
    queue<Coordinate> q;
    q.push({x, y, 0});
    vis[x][y] = 1;
    while (!q.empty())
    {
        auto f = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = f.x + dx[i], ny = f.y + dy[i];
            if (!(nx >= 0 && nx < n && ny >= 0 && ny < m))
                continue;
            if (!vis[nx][ny])
            {
                q.push({nx, ny, f.step + 1});
                vis[nx][ny] = 1;
                if (grid[nx][ny])
                    return f.step + 1;
            }
        }
    }
    return -1;
}
int maxDistance_1(vector<vector<int>> &grid)
{
    n = grid.size();
    m = grid[0].size();
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!grid[i][j])
                ans = max(ans, findNearestLand(grid, i, j));
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> vii1{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    vector<vector<int>> vii2{{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    //cout << maxDistance(vii1) << ' ' << maxDistance(vii2) << endl;
    cout << maxDistance_1(vii1) << ' ' << maxDistance_1(vii2) << endl;
}