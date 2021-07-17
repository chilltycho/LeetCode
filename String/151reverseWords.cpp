//给定字符串，逐个翻转字符串中每个单词
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string trim_space(string s)
{
    size_t l = 0, r = s.size() - 1;
    while (s[l] == ' ')
        ++l;
    while (s[r] == ' ')
        --r;
    return s.substr(l, r - l + 1);
}
//双指针，从最右边字符开始
string reverseWords(string s)
{
    s = trim_space(s);           //删除首尾空格
    int l = s.size() - 1, r = l; //从末端开始
    string res;
    while (l >= 0)
    {
        while (l >= 0 && s[l] != ' ') //搜索首个空格
            l--;
        res += s.substr(l + 1, r - l) + " "; //添加单词
        while (l >= 0 && s[l] == ' ')        //跳过空格间单词
            l--;
        r = l; //r指向下个单词末尾
    }
    return trim_space(res);
}

int main()
{
    string s = "b";
    cout << reverseWords(s);
}