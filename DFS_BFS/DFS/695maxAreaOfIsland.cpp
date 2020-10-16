//最大岛屿面积
#include <iostream>
#include <vector>
using namespace std;

bool inArea(vector<vector<int>> &grid, int r, int c)
{
    int row = grid.size();
    int col = grid[0].size();
    if (0 <= r && r < row && 0 <= c && c < col)
        return true;
    return false;
}

int dfs(vector<vector<int>> &grid, int r, int c)
{
    if (!inArea(grid, r, c))
        return 0;
    if (grid[r][c] != 1)
        return 0;
    grid[r][c] = 2;

    return 1 + dfs(grid, r - 1, c) + dfs(grid, r + 1, c) + dfs(grid, r, c - 1) + dfs(grid, r, c + 1);
}

int dfs_1(vector<vector<int>> &grid, int r, int c)
{
    if (inArea(grid, r, c) && grid[r][c] == 1)
    {
        grid[r][c] = 2;
        return 1 + dfs_1(grid, r - 1, c) 
        + dfs_1(grid, r + 1, c) 
        + dfs_1(grid, r, c - 1)
        + dfs_1(grid, r, c + 1);
    }
    else
        return 0;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int res = 0;
    for (int r = 0; r < grid.size(); r++)
        for (int c = 0; c < grid[0].size(); c++)
        {
            if (grid[r][c] == 1)
            {
                int area = dfs_1(grid, r, c);
                res = max(res, area);
            }
        }
    return res;
}

int main()
{
    vector<vector<int>> vii{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << maxAreaOfIsland(vii);
}