#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//找出一个海洋区域(0)，海洋区域离他最近的陆地(1)区域的距离最大。距离为曼哈顿距离：[x0,y0] [x1,y1]间距离|x0-x1|+|y0-y1|,若只有海洋或陆地，则返回-1
//

//以陆地为起点，向外bfs，可同时在为1的点bfs，称为多源bfs
bool inArea(const vector<vector<int>> &grid, int r, int c) {
  return 0 <= r && r < grid.size() && 0 <= c && c < grid[0].size();
}

int maxDistance(vector<vector<int>> grid) {
  int N = grid.size();
  deque<vector<int>> mq;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == 1)
        mq.push_back({i, j});
    }
  }
  if (mq.empty() || mq.size() == N * N)
    return -1;
  vector<vector<int>> moves{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int distance = -1; //只有陆地或者海洋时，返回-1
  while (!mq.empty()) {
    distance++; //由于每次总是x或y轴移动一次，所以每次距离加1
    int n = mq.size();
    for (int i = 0; i < n; i++) //层序
    {
      vector<int> node = mq.front();
      mq.pop_front();
      int r = node[0];
      int c = node[1];
      for (auto move : moves) {
        int r2 = r + move[0];
        int c2 = c + move[1];
        if (inArea(grid, r2, c2) && grid[r2][c2] == 0) {
          grid[r2][c2] = 2;
          mq.push_back({r2, c2});
        }
      }
    }
  }
  return distance;
}

int main() {
  vector<vector<int>> vii1{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  vector<vector<int>> vii2{{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  // cout << maxDistance(vii1) << ' ' << maxDistance(vii2) << endl;
  cout << maxDistance(vii1) << ' ' << maxDistance(vii2) << endl;
}