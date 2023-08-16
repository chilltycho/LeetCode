// 实现atoi，不合法的输出0，截取到INT_MIN到INT_MAX内
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_map<string, unordered_set<string>> um{
    {"start", {"start", "end", "in_number", "signed"}},
    {"signed", {"in_number", "end"}},
    {"in_number", {"in_number", "end"}},
    {"end", {"end"}}};

string getType(char c) {
  if (isspace(c))
    return "start";
  if (c == '+' || c == '-')
    return "signed";
  if (isdigit(c))
    return "in_number";
  return "end";
}

int matoi(string s) {
  long long res = 0;
  int sign = 1;
  string state{"start"};
  for (auto c : s) {
    string nstate = getType(c);
    if (um[state].find(nstate) != um[state].end()) {
      if (nstate == "in_number") {
        res = res * 10 + c - '0';
        res = sign == 1 ? min(res, (long long)INT_MAX)
                        : min(res, -(long long)INT_MIN);
      } else if (nstate == "signed") {
        sign = c == '+' ? 1 : -1;
      }
      state = nstate;
    } else
      break;
  }
  return res;
}

int myAtoi(string str) {
  int len = str.size();
  int index = 0;
  // 去除前导空格
  while (index < len) {
    if (str[index] != ' ')
      break;
    ++index;
  }
  if (index == len)
    return 0;
  int sign = 1;
  if (str[index] == '+')
    ++index;
  else if (str[index] == '-') {
    ++index;
    sign = -1;
  }

  int res = 0;
  while (index < len) {
    char cur = str[index];
    if (cur < '0' || cur > '9')
      break;
    if (res > INT_MAX / 10 ||
        (res == INT_MAX / 10 && (cur - '0') > INT_MAX % 10))
      return INT_MAX;
    if (res < INT_MIN / 10 ||
        (res == INT_MIN / 10 && (cur - '0') > -(INT_MIN % 10)))
      return INT_MIN;
    res = res * 10 + sign * (cur - '0');
    ++index;
  }
  return res;
}

int main() {
  string s{"+-12"};
  cout << matoi(s) << endl;
}

