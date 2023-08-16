//数字以0123456789101111213...格式序列化到字符序列中，求第n位对应的数字
#include <iostream>
using namespace std;
/*将101112...每位称为数位，记为n
将10,11,12成为数字，记为num
数字位数记为digit
每digit位数起始数字(1,10,100..)记为start
各digit下数位数量count=9*start*digit

1.先确定n位数digit
2.确定n所在数字num
3.确定n是num中哪一数位*/
int findNthDigit(int n) {
  size_t digit = 1;
  size_t start = 1;
  size_t count = 9;
  while (n > count) {
    n -= count;
    digit++;
    start *= 10;
    count = digit * start * 9;
  }
  //确定数位所在数字
  size_t num = start + (n - 1) / digit;
  string nums = to_string(num);
  return nums[(n - 1) % digit] - '0';
}

int main() {
  cout << findNthDigit(15) << endl;
  /*n=15 n-9=6>0 n-9-180<0
  得到digit=2 start=10 n=6 为两位数的start=10开始的第6个数位
  num=start+(n-1)/digit=12 所在数位在数字num=12中
  在(n-1)%digit=1,所求数位为2
  */
}

