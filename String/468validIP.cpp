#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s, char c) {
  int l = 0, r = 0;
  int n = s.size();
  vector<string> res;
  while (r < n) {
    while (r < n && s[r] != c)
      ++r;
    res.push_back(s.substr(l, r - l));
    ++r;
    l = r;
  }
  if (n > 0 && s.back() == c) // 防止最后一个为:或.
    res.push_back(string{});
  return res;
}

bool is4(string IP) {
  auto ip = split(IP, '.');
  if (ip.size() != 4)
    return false;
  for (auto s : ip) {
    if (s.empty() || (s.size() > 1 && s[0] == '0') || s.size() > 3)
      return false;
    for (auto c : s)
      if (!isdigit(c))
        return false;
    int num = stoi(s);
    if (num < 0 || num > 255)
      return false;
  }
  return true;
}

bool is6(string IP) {
  auto ip = split(IP, ':');
  if (ip.size() != 8)
    return false;
  for (auto s : ip) {
    if (s.empty() || s.size() > 4)
      return false;
    for (auto c : s)
      if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') ||
            (c >= 'a' || c <= 'f')))
        return false;
  }
  return true;
}

string validIPAddress(string IP) {
  if (is4(IP))
    return "IPv4";
  if (is6(IP))
    return "IPv6";
  return "Neither";
}

