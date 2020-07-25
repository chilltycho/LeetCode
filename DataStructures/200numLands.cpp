/*
由'1'陆地和'0'水组成的二维网格，计算网格中岛屿数量。
岛屿总被水包围，每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
*/
#include <iostream>
#include <vector>
using namespace std;

//DFS遍历：访问相邻极点+判断base case
#if 0
void dfsTree(TreeNode root)
{
    if(root==nullptr)//base case
        return;
    dfsTree(root->left);//相邻
    dfsTree(root->right);//相邻
}
#endif
#if 0
//对网格，[r,c]相邻四格分别为[r-1,c], [r+1,c],[r,c-1],[r,c+1]。 base case:数组越界
void dfs(vector<vector<int>>& grid, int r, int c)
{
    if (!inArea(grid, r, c))
        return;
    grid[r][c] = 2; //已经遍历过，防止陷入重复遍历，如全为1
    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
}
bool inArea(vector<vector<int>> grid, int r, int c)
{
    return 0 <= r && r < grid.size() && 0 <= c && c < grid[0].size();
}
#endif
bool inArea(vector<vector<char>> grid, int r, int c)
{
    return 0 <= r && r < grid.size() && 0 <= c && c < grid[0].size();
}
void dfs(vector<vector<char>> &grid, int r, int c)
{//上面太慢
        int nr = grid.size();
        int nc = grid[0].size();
        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
}

int numIslands(vector<vector<char>> &grid)
{
    int nr = grid.size();
    if (!nr)
        return 0;
    int nc = grid[0].size();
    int num_islands = 0;
    for (int i = 0; i < nr; ++i)
    {
        for (int j = 0; j < nc; j++)
        {
            if (grid[i][j] == '1')
            {
                ++num_islands;
                dfs(grid, i, j);
            }
        }
    }
    return num_islands;
}

int main()
{
    vector<vector<char>> vvc{{'1', '1', '1', '1', '0'},
                             {'1', '1', '0', '1', '0'},
                             {'1', '1', '0', '0', '0'},
                             {'0', '0', '0', '0', '0'}};
    cout << numIslands(vvc);
}