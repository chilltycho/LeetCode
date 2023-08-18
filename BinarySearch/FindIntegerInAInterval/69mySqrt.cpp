//计算并返回x的平方根,结果只保留整数部分
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

//一个数的平方根最多不会超过它的一半
int mySqrt_bi(int x) {
  if (x == 0 || x == 1)
    return x;
  int l = 1, r = x / 2;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (m < x / m) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  if (x / l < l)
    return l - 1;
  return l;
}
/*
牛顿迭代法
x1 = x0 - f(x0)/f'(x0) x1比x0更接近根
这里f(x)=x^2-a
*/
int mySqrt_newton(int x) {
  if (x == 0 || x == 1)
    return x;
  double c = x, x0 = x;
  while (true) {
    double xi = 0.5 * (x0 + c / x0);
    if (fabs(x0 - xi) < 1e-7)
      return int(x0);
    x0 = xi;
  }
  return -1;
}

int main() { cout << mySqrt_bi(4) << endl; }

