//求1-n整数中1出现的次数
#include <iostream>
using namespace std;
/*将1-n的个位、十位、百位..的1出现次数相加，即为1出现总次数
称ni为当前位，记为cur 
称ni-1 ni-2为低位记为low
ni+1 ni+2记为高位
10^i称为位因子，记为digit

当cur为0,个数为high*digit
当cur为1,个数为high*digit+low+1
当cur>1,个数为(high+1)*digit*/
int countOne(int n) {
  int digit = 1, res = 0;
  int high = n / 10, cur = n % 10, low = 0;
  while (high != 0 || cur != 0) {
    if (cur == 0)
      res += high * digit;
    else if (cur == 1)
      res += high * digit + low + 1;
    else
      res += (high + 1) * digit;

    low += cur * digit;
    cur = high % 10;
    high /= 10;
    digit *= 10;
  }
  return res;
}

int main() {
  cout << sizeof(size_t) << endl;
  cout << sizeof(int) << endl;
}

