#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//坏橘子为2，好的为1，没橘子为0，相邻每分钟可感染，求感染所有的分钟数，若无法全部感染，返回-1
bool inArea(vector<vector<int>> &grid, int r, int c) {
  int row = grid.size();
  int col = grid[0].size();
  return 0 <= r && r < row && 0 <= c && c < col;
}

int orangeRotting(vector<vector<int>> &grid) //从2开始多源bfs，若相邻为1，感染。
{
  int row = grid.size();
  int col = grid[0].size();
  vector<vector<int>> moves{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  queue<vector<int>> mq;
  int count1 = 0, minutes = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (grid[i][j] == 2)
        mq.push({i, j});
      if (grid[i][j] == 1)
        count1++;
    }
  }
  while (count1 > 0 && !mq.empty()) {
    int n = mq.size();
    for (int i = 0; i < n; i++) //层序
    {
      auto pos = mq.front();
      int r = pos[0];
      int c = pos[1];
      mq.pop();
      for (auto move : moves) {
        int r1 = r + move[0];
        int c1 = c + move[1];
        if (inArea(grid, r1, c1) && grid[r1][c1] == 1) {
          grid[r1][c1] = 2;
          count1--;
          mq.push({r1, c1});
        }
      }
    }
    minutes++;
  }
  if (count1 == 0)
    return minutes; //考虑输入为0，minutes为-1
  else
    return -1; //还有不可能腐烂的橘子
}

int main() {
  vector<vector<int>> vii{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  vector<vector<int>> vii1{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
  vector<vector<int>> vii2{{0, 2}};
  cout << orangeRotting(vii);
}

