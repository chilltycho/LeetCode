//给定数组A，构建数组B,B[i]为A中所有元素相乘/A[i]
#include <iostream>
#include <vector>
using namespace std;

vector<int> constructArr(vector<int> &a) {
  if (a.empty())
    return vector<int>{0};
  vector<int> b(a.size());
  b[0] = 1; //对角线为1
  int tmp = 1;
  for (int i = 1; i < a.size(); i++) //下三角
    b[i] = b[i - 1] * a[i - 1];
  for (int i = a.size() - 2; i >= 0; i--) //上三角
  {
    tmp *= a[i + 1];
    b[i] *= tmp;
  }
  return b;
}

int main() {
  vector<int> A{1, 2, 3, 4, 5};
  vector<int> B{120, 60, 40, 30, 24};
}

