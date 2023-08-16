// 较小的值可能是答案，标记较小的值
int mysqrt(int x) {
  int l = 0, r = x, ans = -1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (x / m == m)
      return m;
    else if (x / m > m) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return ans;
}

int mysqrt(int x) {
  if (x == 0 || x == 1)
    return x;
  int l = 0, r = x;
  while (l < r) {
    int m = l + (r - l + 1) / 2;
    if (m > x / m)
      r = m - 1;
    else
      l = m;
  }
  return l;
}

