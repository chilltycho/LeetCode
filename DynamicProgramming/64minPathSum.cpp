/**
 * 给定包含非负整数mxn网格grid，找出一条从左上角到右下角的路径，
 * 使得路径上数字总和最小。每次只能向下或向右移动一步
 */
#include <iostream>
#include <vector>
using namespace std;
int minPathSum(vector<vector<int>> &grid) {
  int r = grid.size();
  int c = grid[0].size();
  for (int i = 1; i < r; i++)
    grid[i][0] += grid[i - 1][0];
  for (int j = 1; j < c; j++)
    grid[0][j] += grid[0][j - 1];
  for (int i = 1; i < r; i++) {
    for (int j = 1; j < c; j++) {
      grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
    }
  }
  return grid[r - 1][c - 1];
}

int main() {
  vector<vector<int>> dp{{1, 2, 3}, {4, 5, 6}};
  cout << minPathSum(dp) << endl;
}