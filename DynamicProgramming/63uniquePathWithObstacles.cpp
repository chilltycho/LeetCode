/*机器人从m*n网格左上角出发，只能向下向右，试图到达右下角。
考虑障碍物，求路径数。[1]表示有障碍物*/
#include <vector>
#include <iostream>
using namespace std;

int uniquePathWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int r = obstacleGrid.size(), c = obstacleGrid[0].size();
    vector<vector<int>> dp(r, vector<int>(c, 0));
    for (int i = 0; i < r && obstacleGrid[i][0] == 0; i++)
        dp[i][0] = 1;
    for (int j = 0; j < c && obstacleGrid[0][j] == 0; j++)
        dp[0][j] = 1;
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
            if (obstacleGrid[i][j] == 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
    return dp[r - 1][c - 1];
}

int main()
{
    vector<vector<int>> grid{{0, 0}, {1, 1}, {0, 0}};
    cout << uniquePathWithObstacles(grid)<<endl;
}