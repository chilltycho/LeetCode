/*给定非负整数num，对[0..num]，计算二进制树中1的数目并作为数组返回*/
#include <iostream>
#include <vector>
using namespace std;

int countOnes(int x) {
  int ones = 0;
  while (x > 0) {
    x &= (x - 1);
    ++ones;
  }
  return ones;
}

vector<int> countBits(int n) {
  vector<int> res(n + 1);
  for (int i = 0; i <= n; ++i)
    res[i] = countOnes(i);
  return res;
}

vector<int> countBits_dp(int n) {
  vector<int> res(n + 1, 0);
  int highBit = 0;
  for (int i = 1; i <= n; ++i) {
    if ((i & (i - 1)) == 0) // i是2的幂
      highBit = i;
    res[i] = res[i - highBit] + 1;
  }
  return res;
}

int main() {
  countBits(2); //[0, 1, 1]
  countBits(5); //[0,1,1,2,1,2]
}

