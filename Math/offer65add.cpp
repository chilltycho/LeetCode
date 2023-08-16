//用位运算求两个整数之和
#include <iostream>
using namespace std;

int add(int a, int b) {
  //进位为0时跳出
  while (b != 0) {
      int c = (unsigned int)(a & b) << 1; //进位
      a ^= b;                             //非进位和
      b = c;                              //进位
  }
  return a;
}
