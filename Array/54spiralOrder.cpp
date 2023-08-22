#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
  int left = 0, right = matrix[0].size() - 1, top = 0, down = matrix.size() - 1;
  vector<int> res;

  while (true) {
    // 从左至右
    for (int i = left; i <= right; i++) {
      res.push_back(matrix[top][i]);
    }
    if (++top > down) {
      break;
    }
    // 从上至下
    for (int i = top; i <= down; i++) {
      res.push_back(matrix[i][right]);
    }
    // 从右至左
    if (--right < left) {
      break;
    }
    for (int i = right; i >= left; i--) {
      res.push_back(matrix[down][i]);
    }
    // 从下至上
    if (--down < top) {
      break;
    }
    for (int i = down; i >= top; i--) {
      res.push_back(matrix[i][left]);
    }
    if (++left > right) {
      break;
    }
  }
  return res;
}

int main() {
  vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  auto res = spiralOrder(matrix);
  for (const auto &c : res)
    cout << c << ' ';
}
