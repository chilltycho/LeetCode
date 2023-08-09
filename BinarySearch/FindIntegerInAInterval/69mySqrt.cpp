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
不断用(x, f(x))切线来逼近x^2-a=0的根。x-f(x)/(2x)比x更接近解。代入f(x)=x^2-a
得到x-(x^2-a)/(2x)，即(x+a/x)/2
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