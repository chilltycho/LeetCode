#include <iostream>
#include <vector>
#include <set>
using namespace std;
//二维地图上，0代表海洋，1代表陆地，只能将一格0变为1，求最大岛屿面积
bool inArea(vector<vector<int>> &grid, int r, int c)
{
    int row = grid.size();
    int col = grid[0].size();
    if (0 <= r && r < row && 0 <= c && c < col)
        return true;
    return false;
}
int dfs(vector<vector<int>> &grid, int r, int c) //计算面积
{
    if (inArea(grid, r, c) && grid[r][c] == 1)
    {
        grid[r][c] = 2;
        return 1 + dfs(grid, r - 1, c) + dfs(grid, r + 1, c) + dfs(grid, r, c - 1) + dfs(grid, r, c + 1);
    }
    else
        return 0;
}
int largestIsland(vector<vector<int>> &grid) //对每个0暂时变为1，再统计连通块大小
{
    int maxArea = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0)
            {
                grid[i][j] = 1;
                int area = dfs(grid, i, j);
                maxArea = max(area, maxArea);
                grid[i][j] = 0; //回溯
            }
        }
    }
    if (maxArea == 0)
        return grid.size() * grid[0].size();
    return maxArea;
}

//法二，对每个连通块，将所有陆地赋值为index并记录大小area[index],对每个0，查找周围区域大小并计入结果
int dfs_1(vector<vector<int>> &grid, int r, int c, int index)
{
    if (inArea(grid, r, c) && grid[r][c] == 1)
    {
        grid[r][c] = index;
        return 1 + dfs_1(grid, r - 1, c, index) +
               dfs_1(grid, r + 1, c, index) +
               dfs_1(grid, r, c - 1, index) +
               dfs_1(grid, r, c + 1, index);
    }
    else
        return 0;
}

int largestIsLand(vector<vector<int>> &grid)
{
    const int size = grid.size();
    int index = 2;
    int *area = new int[size * size + 2]{0};
    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
            if (grid[r][c] == 1)
            {
                area[index] = dfs_1(grid, r, c, index);
                index++;
            }
    int ans = 0;
    for (int i = 2; i < size * size + 2; i++)
    {
        ans = max(ans, area[i]);
    }
    for (int r = 0; r < size; ++r)
    {
        for (int c = 0; c < size; ++c)
            if (grid[r][c] == 0)
            {
                set<int> seen;
                if (r - 1 >= 0 && grid[r - 1][c] > 1)
                    seen.insert(grid[r - 1][c]);
                if (r + 1 < size && grid[r + 1][c] > 1)
                    seen.insert(grid[r + 1][c]);
                if (c - 1 >= 0 && grid[r][c - 1] > 1)
                    seen.insert(grid[r][c - 1]);
                if (c + 1 < size && grid[r][c + 1] > 1)
                    seen.insert(grid[r][c + 1]);
                int bns = 1;
                for (auto i = seen.begin(); i != seen.end(); i++)
                {
                    bns += area[*i];
                }
                ans = max(ans, bns);
            }
    }
    return ans;
}

int main()
{
    vector<vector<int>> vii1{{1, 0}, {0, 1}};
    vector<vector<int>> vii2{{1, 1}, {1, 0}};
    vector<vector<int>> vii3{{1, 1}, {1, 1}};
    //cout << largestIsland(vii1) << ' ' << largestIsland(vii2) << ' ' << largestIsland(vii3) << endl;
    cout << largestIsLand(vii1) << ' ' << largestIsLand(vii2) << ' ' << largestIsLand(vii3) << endl;
}