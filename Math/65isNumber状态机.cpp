/*
有效数字（按顺序）可以分成以下几个部分：
1. 一个 小数 或者 整数
2.（可选）一个 'e' 或 'E' ，后面跟着一个 整数

小数（按顺序）可以分成以下几个部分：
1.（可选）一个符号字符（'+' 或 '-'）
2.至少一位数字，后面跟着一个点 '.'
3.至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
4.一个点 '.' ，后面跟着至少一位数字

整数（按顺序）可以分成以下几个部分：
1. （可选）一个符号字符（'+' 或 '-'）
2. 至少一位数字

部分有效数字列举如下：
["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1",
"53.5e93", "-123.456e789"]

部分无效数字列举如下：
["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]
*/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// 所有状态：符号位，整数部分，，左侧有整数的小数点，左侧无整数的小数点，小数部分，字符e，指数部分符号位，指数部分整数部分
enum State {
  STATE_INITIAL,
  STATE_INT_SIGN,
  STATE_INTEGER,
  STATE_POINT,
  STATE_POINT_WITHOUT_INT,
  STATE_FRACTION,
  STATE_EXP,
  STATE_EXP_SIGN,
  STATE_EXP_NUMBER,
  STATE_END,
};

enum CharType {
  CHAR_NUMBER,
  CHAR_EXP,
  CHAR_POINT,
  CHAR_SIGN,
  CHAR_ILLEGAL,
};

CharType toCharType(char ch) {
  if (ch >= '0' && ch <= '9') {
    return CHAR_NUMBER;
  } else if (ch == 'e' || ch == 'E') {
    return CHAR_EXP;
  } else if (ch == '.') {
    return CHAR_POINT;
  } else if (ch == '+' || ch == '-') {
    return CHAR_SIGN;
  } else {
    return CHAR_ILLEGAL;
  }
}
unordered_map<State, unordered_map<CharType, State>> transfer{
    {STATE_INITIAL,
     {
         {CHAR_NUMBER, STATE_INTEGER},
         {CHAR_POINT, STATE_POINT_WITHOUT_INT},
         {CHAR_SIGN, STATE_INT_SIGN},
     }},
    {STATE_INT_SIGN,
     {
         {CHAR_NUMBER, STATE_INTEGER},
         {CHAR_POINT, STATE_POINT_WITHOUT_INT},
     }},
    {STATE_INTEGER,
     {
         {CHAR_NUMBER, STATE_INTEGER},
         {CHAR_EXP, STATE_EXP},
         {CHAR_POINT, STATE_POINT},
     }},
    {STATE_POINT,
     {
         {CHAR_NUMBER, STATE_FRACTION},
         {CHAR_EXP, STATE_EXP},
     }},
    {STATE_POINT_WITHOUT_INT,
     {
         {CHAR_NUMBER, STATE_FRACTION},
     }},
    {STATE_FRACTION,
     {
         {CHAR_NUMBER, STATE_FRACTION},
         {CHAR_EXP, STATE_EXP},
     }},
    {STATE_EXP,
     {
         {CHAR_NUMBER, STATE_EXP_NUMBER},
         {CHAR_SIGN, STATE_EXP_SIGN},
     }},
    {STATE_EXP_SIGN,
     {
         {CHAR_NUMBER, STATE_EXP_NUMBER},
     }},
    {STATE_EXP_NUMBER,
     {
         {CHAR_NUMBER, STATE_EXP_NUMBER},
     }}};
//删除两端空格
string removespace(string &s)  {
  string res{};
  int l = 0, r = s.size() - 1;
  while (s[l] == ' ')
    ++l;
  if (l >= s.size())
    return res;
  while (s[r] == ' ')
    --r;
  if (r < 0)
    return res;
  res.assign(s.begin() + l, s.begin() + r + 1);
  return res;
}

bool isNumber(string s) {
  s = removespace(s);
  int len = s.size();
  State st = STATE_INITIAL;
  for (int i = 0; i < len; i++) {
    CharType typ = toCharType(s[i]);
    // 不存在从st状态接typ转换为另一状态
    if (transfer[st].find(typ) == transfer[st].end()) {
      return false;
    } else {
      st = transfer[st][typ]; // 后一状态
    }
  }
  return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION ||
         st == STATE_EXP_NUMBER || st == STATE_END;
}

bool isNumeric_1(string s) {
  removespace(s);
  bool sign = false;
  bool num = false; //整数部分
  bool dec = false; //小数部分
  bool point = 0;   //小数点
  bool exp = 0;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] == '+' || s[i] == '-') {
      if (sign)
        return false; //重复符号
      if (i == 0 || s[i - 1] == 'E' || s[i - 1] == 'e')
        sign = true; // 符号位只能出现位置
      else
        return false;
    } else if (s[i] == '.') {
      if (exp || point)
        return false; // 小数点不能在e之后，不能重复
      point = true;
    } else if (s[i] == 'e' || s[i] == 'E') {
      if (exp || (num == false && dec == false))
        return false;
      else {
        sign = false, num = false, dec = false, exp = true;
      }
    } else if (s[i] >= '0' && s[i] <= '9') {
      if (num == false || exp == true)
        num = true;
      else if (point)
        dec = true;
    } else
      return false;
  }
  return num || dec;
}

int main() {
  string res{"1 "};
  cout << isNumber(res) << endl;
}
