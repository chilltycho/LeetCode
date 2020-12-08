#include <vector>
#include <iostream>
using namespace std;
int minPathSum(vector<vector<int>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    for (int i = 1; i < r; i++)
        grid[i][0] += grid[i - 1][0];
    for (int j = 1; j < c; j++)
        grid[0][j] += grid[0][j - 1];
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < r; j++)
        {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[r - 1][c - 1];
}

int main()
{
    vector<vector<int>> dp{{1, 2, 3}, {4, 5, 6}};
    cout << minPathSum(dp) << endl;
}