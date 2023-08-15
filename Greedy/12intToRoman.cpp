/*罗马数字包含七种字符:I(1),V(5),X(10),L(50),C(100),D(500),M(1000)
IV(4) IX(9) XL(40) XC(90) CD(400) CM(900)*/
#include <cassert>
#include <iostream>
using namespace std;
/**
 * 尽可能使用较大数值对应的字符，最后转换的罗马数字的字符个数更少。
 *
 */
string intToRoman(int num) {
  int nums[13]{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  string romans[13]{"M",  "CM", "D",  "CD", "C",  "XC", "L",
                    "XL", "X",  "IX", "V",  "IV", "I"};
  int index = 0;
  string res;
  while (index < 13) {
    while (num >= nums[index]) {
      res += romans[index];
      num -= nums[index];
    }
    index++;
  }
  return res;
}

int main() {
  assert("III" == intToRoman(3));
  assert("IV" == intToRoman(4));
}