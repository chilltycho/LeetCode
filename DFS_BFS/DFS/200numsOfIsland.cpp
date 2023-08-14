#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &grid, int r, int c) {
  int nr = grid.size();
  int nc = grid[0].size();
  grid[r][c] = '0';
  if (r - 1 >= 0 && grid[r - 1][c] == '1')
    dfs(grid, r - 1, c);
  if (r + 1 < nr && grid[r + 1][c] == '1')
    dfs(grid, r + 1, c);
  if (c - 1 >= 0 && grid[r][c - 1] == '1')
    dfs(grid, r, c - 1);
  if (c + 1 < nc && grid[r][c + 1] == '1')
    dfs(grid, r, c + 1);
}

int numsIsland(vector<vector<char>> &grid) {
  int nr = grid.size();
  if (nr == 0)
    return 0;
  int nc = grid[0].size();
  int res = 0;
  for (int r = 0; r < nr; r++) {
    for (int c = 0; c < nc; c++) {
      if (grid[r][c] == '1') {
        res++;
        dfs(grid, r, c);
      }
    }
  }
  return res;
}
