#include <algorithm>
#include <iostream>
using namespace std;

string addBinary(string a, string b) {
  string ans;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  auto n = max(a.size(), b.size());
  size_t carry = 0;
  for (size_t i = 0; i < n; i++) {
    carry += i < a.size() ? (a[i] == '1') : 0;
    carry += i < b.size() ? (b[i] == '1') : 0;
    ans.push_back((carry % 2) ? '1' : '0');
    carry /= 2;
  }
  if (carry)
    ans.push_back('1');
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() { cout << addBinary("1010", "1011"); }

