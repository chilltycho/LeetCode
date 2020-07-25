#include <unordered_map>
#include <iostream>
using namespace std;
//返回第一个不重复的元素索引，若没有则返回-1，假定都是小写字母
int firstUniqueChar(string s)
{
    unordered_map<int, int> count;
    int size = s.length();
    for (auto c : s)
        count[c - 'a']++;

    for (int i = 0; i < s.length(); i++)
        if (count[s[i] - 'a'] == 1)
            return i;
    return -1;
}

int main()
{
    string s="loveleetcode";
    cout<<firstUniqueChar(s);
}