#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &grid, int r, int c)
{
    if (!(0 <= r && r < grid.size() && 0 <= c && c < grid[0].size())) //边界+1
        return 1;
    if (grid[r][c] == 0) //相邻0加一
        return 1;
    if (grid[r][c] != 1) //走过的陆地
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

//法2，每个岛周长为4，若有一个岛相邻，减2。周长=每块岛屿*4-每相邻*2
int islandPerimeter_1(vector<vector<int>> &grid)
{
    int res = 0;
    int row = grid.size();
    int col = grid[0].size();
    for (int i = 0; i < row; i++) //从左到右，从上到下遍历。只需看当前陆地是否与左或上方陆地相邻
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
            {
                res += 4;
                if (i - 1 >= 0 && grid[i - 1][j] == 1)
                    res -= 2;
                if (j - 1 >= 0 && grid[i][j - 1] == 1)
                    res -= 2;
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> vii{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    //cout << islandPerimeter(vii) << endl;
    cout << islandPerimeter_1(vii) << endl;
}