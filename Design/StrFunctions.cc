#include <bits/stdc++.h>
using namespace std;
char *my_strcat(char *dest, const char *src) {
  char *rdest = dest;

  while (*dest)
    dest++;
  while (*dest++ = *src++)
    ;
  return rdest;
}

int mstrlen(const char *s) {
  int n;
  for (n = 0; s[n]; n++)
    ;
  return n;
}

char *mstrcpy(char *s, const char *t) {
  char *os;

  os = s;
  while ((*s++ = *t++) != 0)
    ;
  return os;
}

void *memmove(void *dest, const void *src, size_t count) {
  if (dest == NULL || src == NULL || count <= 0)
    return NULL;
  if (dest < src) {
    char *d = (char *)dest;
    char *s = (char *)src;
    while (count--) {
      *d++ = *s++;
    }
  } else { // 从后往前拷贝
    char *d = (char *)dest + count;
    char *s = (char *)src + count;
    while (count--) {
      *--d = *--s;
    }
  }
  return dest;
}

int strCmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

void *memcpy(void *dest, const void *src, size_t count) {
  if (dest == NULL || src == NULL || count <= 0)
    return NULL;
  char *d = (char *)dest;
  char *s = (char *)src;
  while (count--) {
    *d++ = *s++;
  }
  return dest;
}

int main() {
  string s{};
  cout << s.size() << endl;
  cout << sizeof(s.c_str()) << endl;
}

