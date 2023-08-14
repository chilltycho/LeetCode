/*
最大正方形：在由'0'和'1'组成二维矩阵内，找到只含'1'的最大正方形。
*/
#include <vector>
using namespace std;
/*
dp[i][j]表示以(i,j)为右下角，只包含1的正方形的边长最大值。
dp[i][j]=min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1])+1
*/

int maximalSquare(vector<vector<char>> &matrix) {
  if (matrix.size() == 0 || matrix[0].size() == 0) {
    return 0;
  }

  int maxSize = 0;
  int row = matrix.size(), col = matrix[0].size();
  vector<vector<int>> dp(row, vector<int>(col));
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      if (matrix[i][j] == '1') {
        if (i == 0 || j == 0)
          dp[i][j] = 1;
        else
          dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
      }
      maxSize = max(maxSize, dp[i][j]);
    }
  }
  return maxSize * maxSize;
}

