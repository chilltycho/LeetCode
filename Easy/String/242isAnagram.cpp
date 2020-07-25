#include <iostream>
using namespace std;
//有效异位词，两字符串字母相同，顺序不同
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    int x[26]{0}, y[26]{0};
    for (auto c : s)
        x[c - 'a']++;
    for (auto c : t)
        y[c - 'a']++;

    for (int i = 0; i < 26; i++)
        if (x[i] != y[i])
            return false;
    return true;
}

int main()
{
    string s = "rat", t = "car";
    cout << isAnagram(s, t);
}