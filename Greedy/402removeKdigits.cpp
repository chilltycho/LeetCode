//给定一个以字符串表示的非负整数,移除k位数字,使剩下数字最小
#include <iostream>
#include <queue>
using namespace std;
// 转化为保留n-k个
string removeKdigits_1(string num, int k) {
  int n = num.size();
  string vec = "";
  int res = n - k; // 剩余位数
  if (res == 0)
    return "0";
  for (auto c : num) {
    // 还可删除位&&仍有位可删除&&当前位c比左侧小，删除左侧元素
    while (k != 0 && !vec.empty() && vec.back() > c) {
      vec.pop_back();
      --k;
    }
    vec.push_back(c);
  }
  vec = vec.substr(0, res);                      // 若递增，只取前res位
  while (*vec.begin() == '0' && vec.size() != 1) // 前缀0
    vec.erase(vec.begin());
  return vec;
}


//从左至右迭代,移除大的数,若没有移除完则直接去除后面的.但对单调增序列失效,需移除末尾的数字获得最小数
string removeKdigits(string num, int k) {
  if (k == num.size())
    return "0";
  deque<char> si;
  for (char digit : num) {
    while (si.size() > 0 && k > 0 &&
           si.front() > digit) {
      //低位值小于高位值,移除高位值
      si.pop_front();
      k--;
    }
    si.push_front(digit);
  }
  for (int i = 0; i < k; i++){
    si.pop_front();
  }
  string ret;
  bool leadingZero = true;
  while (!si.empty()) {
    char digit = si.back();
    si.pop_back();
    if (leadingZero && digit == '0')
      continue;
    leadingZero = false;
    ret.push_back(digit);
  }
  if (ret.empty())
    return "0";
  return ret;
}

int main() {
  cout << removeKdigits_1("1432219", 3) << endl; // 1219,移除4,3,2
  cout << removeKdigits_1("10200", 1) << endl;   // 200,移除1
  string s{"1234"};
}

