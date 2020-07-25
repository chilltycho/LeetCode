#include <iostream>
#include <vector>
using namespace std;
#if 0
bool inArea(vector<vector<int>>& grid, int r, int c)
{
    int Row = grid.size();
    int Col = grid[0].size();
    if (0 <= r && r < Row && 0 <= c && c < Col)
        return true;
    return false;
}
int countland(vector<vector<int>>& grid, int r, int c)
{
    int res = 0;
    if (inArea(grid, r - 1, c) && (grid[r - 1][c] == 1 || grid[r - 1][c] == 2))
        res++;
    if (inArea(grid, r + 1, c) && (grid[r + 1][c] == 1 || grid[r + 1][c] == 2))
        res++;
    if (inArea(grid, r, c - 1) && (grid[r][c - 1] == 1 || grid[r][c - 1] == 2))
        res++;
    if (inArea(grid, r, c + 1) && (grid[r][c + 1] == 1 || grid[r][c + 1] == 2))
        res++;
    return res;
}
void dfs(vector<vector<int>>& grid, int r, int c, int& count)
{
    if (!inArea(grid, r, c) || grid[r][c] == 0||grid[r][c]==2)
        return;
    grid[r][c] = 2;
    count += (4 - countland(grid, r, c));
    dfs(grid, r - 1, c, count);
    dfs(grid, r + 1, c, count);
    dfs(grid, r, c - 1, count);
    dfs(grid, r, c + 1, count);
}

int islandPerimeter(vector<vector<int>>& grid)
{
    int res = 0;
    int r = grid.size(), c = grid[0].size();
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            dfs(grid, i, j, res);
    return res;
}
#endif
int dfs(vector<vector<int>> &grid, int r, int c)
{
    if (!(0 <= r && r < grid.size() && 0 <= c && c < grid[0].size()))//边界+1
        return 1;
    if (grid[r][c] == 0)//相邻0加一
        return 1;
    if (grid[r][c] != 1)//
        return 0;
    grid[r][c] = 2;
    return dfs(grid, r - 1, c) + dfs(grid, r + 1, c) + dfs(grid, r, c - 1) + dfs(grid, r, c + 1);
}
int islandPerimeter(vector<vector<int>> &grid)
{
    for (int r = 0; r < grid.size(); r++)
        for (int c = 0; c < grid[0].size(); c++)
        {
            if (grid[r][c] == 1)
                return dfs(grid, r, c);
        }
}
int main()
{
    vector<vector<int>> vii{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout << islandPerimeter(vii);
}