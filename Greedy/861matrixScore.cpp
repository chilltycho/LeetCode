/*二维矩阵A每个元素为0或1.移动指将任一行或列，所有0-1反转。
任意次移动后，每行按二进制解释，求最大每行和*/
#include <iostream>
#include <vector>
using namespace std;
/*贪心：从左到右，使每列1尽可能多。先行反转让第一列为全1，然后逐列看，列反转让每行1尽可能多*/
int matrixScore(vector<vector<int>> &A) {
  int row = A.size(), col = A[0].size();
  int ret = row * (1 << (col - 1)); //直接将第一列翻转为1，计算贡献值
  for (int j = 1; j < col; j++) {
    int nOnes = 0; //该列1的个数（考虑第一列变为全一的反转）
    for (int i = 0; i < row; i++) {
      if (A[i][0] == 1) {
        //该行未反转（根据行首元素判断）
        nOnes += A[i][j];
      }
      else {
        nOnes += (1 - A[i][j]);
      }
    }
    int k = max(nOnes, row - nOnes); // 1最多的个数
    ret += k * (1 << (col - j - 1));
  }
  return ret;
}

