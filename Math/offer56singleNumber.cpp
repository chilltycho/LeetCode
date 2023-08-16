//在一个数组nums中除一个数字只出现一次外，其他数字都出现三次。找出只出现一次的数字。
#include <iostream>
#include <vector>
using namespace std;
/*若一个数字出现三次，则二进制表示的每一位也出现三次。将每位分别加起来，
则每位的和都能被3整除。若某位的和能被3整除，
则只出现一次的数字二进制表示中对应的那位为0,否则为1.*/
int singleNumber(vector<int> &nums) {
  if (nums.size() == 0)
    return -1;
  int bitSum[32]{0};
  unsigned int res = 0;
  for (auto &num : nums) {
    unsigned int bitMask = 1;
    for (int i = 31; i >= 0; i--) {
      if ((num & bitMask) != 0) {
        bitSum[i]++;
      }
      bitMask <<= 1;
    }
  }
  for (int i = 0; i < 32; i++) {
    res <<= 1;
    res += bitSum[i] % 3;
  }
  return res;
}

int main() {}

