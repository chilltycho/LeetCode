#include <cassert>
//实现数值整数次方
double myPow_ite(double x, int n) {
  double res = 1.0;
  for (int i = n; i != 0; i /= 2, x *= x) {
    if (i & 1) {
      res *= x;
    }
  }
  return n < 0 ? 1.0 / res : res;
}

double myPow(double x, int n) {
  if (n == 0)
    return 1;
  if (n < 0)
    return 1 / x * myPow(1 / x, -(n + 1));
  // return myPow(1/x,-n); // 若n为INT_MIN,则取负数仍为INT_MIN
  return n & 1 ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
}

int main() { assert(1024 == myPow(2, 10)); }
