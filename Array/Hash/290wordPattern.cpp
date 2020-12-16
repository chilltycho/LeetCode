/*给定规律pattern和字符串str，判断pattern中每个字母和str每个非空单词间存在
双向连接关系*/
#include <unordered_map>
#include <iostream>
#include <unordered_set>
using namespace std;

bool wordPattern(string pattern, string s)
{
    unordered_map<string, char> str2ch;
    unordered_map<char, string> ch2str;
    int m = s.size();
    int i = 0;
    for (auto ch : pattern)
    {
        if (i >= m)
            return false;
        int j = i;
        while (j < m && s[j] != ' ')
            j++;
        string tmp = s.substr(i, j - i);
        if (str2ch.count(tmp) && str2ch[tmp] != ch)
            return false;
        if (ch2str.count(ch) && ch2str[ch] != tmp)
            return false;
        str2ch[tmp] = ch;
        ch2str[ch] = tmp;
        i = j + 1;
    }
    return i >= m;
}

int main()
{
    string pa = "abba";
    string str = "dog cat cat dog";
    cout << wordPattern(pa, str) << endl;
}
