/**
 * 计算num的二进制中1个数，负数用补码表示
 */
int count1(int n) {
  // 对1000..00不适应，-2147483648，实际1个1
  int res = 0;
  while (n) {
    int tmp = n % 2;
    if (tmp == 1)
      res++;
    n /= 2;
  }
  return res;
}

int count1_1(int n) {
  // 对补码不适用，右移左边添1
  int res = 0;
  while (n) {
    if (n & 1)
      ++res;
    n >>= 1;
  }
  return res;
}

int count1_2(int n) {
  // 需左移31次
  int res = 0;
  int mark = 0x01;
  while (mark != 0) {
    if (mark & n)
      res++;
    mark <<= 1;
  }
  return res;
}

// 不断消除较低位的1
int count1_3(int n) {
  // val: 1101000, val-1: 1100111,  val&(val-1): 1100000略过0
  int res = 0;
  while (n) {
    ++res;
    n &= (n - 1);
  }
  return res;
}