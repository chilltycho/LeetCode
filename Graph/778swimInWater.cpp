/*N*N方格grid中,grid[i][j]表示在(i,j)的平台高度.开始下雨,时间t时任意位置
高度为t,水位淹没相邻平台时才能游.假定瞬间可移动无限距离,从[0,0]出发,
最少耗时多久才能到达(N-1,N-1)*/
#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
#include <stack>
using namespace std;
struct T
{
    int height, x, y;
    T(int a, int b, int c) : height(a), x(b), y(c) {}
    bool operator<(const T &d) const { return height > d.height; } //优先队列默认从大到小
};
//所有能走的点中永远只走水位最低的点
int swimIntWater(vector<vector<int>> &grid)
{
    if (grid.empty())
    {
        return 0;
    }
    int N = grid.size();
    int res = 0;
    priority_queue<T> pq;
    pq.push(T(grid[0][0], 0, 0));
    vector<vector<int>> seen(N, vector<int>(N, 0));
    seen[0][0] = 1;
    int dir[4][2]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (true)
    {
        auto cur = pq.top();
        pq.pop();
        res = max(res, cur.height);
        if (cur.x == N - 1 && cur.y == N - 1)
            return res;
        for (auto &d : dir)
        {
            int i = cur.x + d[0];
            int j = cur.y + d[1];
            if (i >= 0 && i < N && j >= 0 && j < N && !seen[i][j])
            {
                seen[i][j] = 1;
                pq.push(T(grid[i][j], i, j));
            }
        }
    }
}

bool dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, vector<int> &dir, int waterHeight,
         int row, int col, int n)
{
    visited[row][col] = 1;
    for (int i = 0; i < 4; i++)
    {
        int r = row + dir[i];
        int c = col + dir[i + 1];
        if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0 && 
            grid[r][c] <= waterHeight)
        {
            if (r == n - 1 && c == n - 1)
                return true;
            if (dfs(grid, visited, dir, waterHeight, r, c, n))
                return true;
        }
    }
    return false;
}

bool valid(vector<vector<int>> &grid, int waterHeight)
{
    int n = grid.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<int> dir{-1, 0, 1, 0, -1};
    return dfs(grid, visited, dir, waterHeight, 0, 0, n);
}

int swimIntWater_binarySearch_DFS(vector<vector<int>> &grid)
{
    if (grid.empty())
        return 0;
    int n = grid.size();
    int low = grid[0][0], hi = n * n - 1;//grid区间[0,N*N-1]
    while (low < hi)
    {
        int mid = low + (hi - low) / 2;
        if (valid(grid, mid))
            hi = mid;
        else
            low = mid+1;
    }
    return low;
}

int main()
{
    vector<vector<int>> vi{{0, 2}, {1, 3}};
    assert(3 == swimIntWater(vi));
    vector<vector<int>> vi1{
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}};
    assert(16 == swimIntWater(vi1));

    vector<vector<int>> vi2{{0, 1, 4}, {2, 8, 7}, {3, 6, 5}}; //最优路径并非start周围最低点
    assert(6 == swimIntWater(vi2));
}