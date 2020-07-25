#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*给定一个字符串，逐个反转字符串中每个单词
输入："the sky is blue"
输出：“bule is sky the"
无空格字符串构成一个单词，输入字符串可在前面或后面包含多余空格，但反转后字符串不能包括
如果两个单词间有多余空格，将反转后单词间空格减少到一个
*/
string reverseWords(string s)//先反转整个字符串，再遇到一个单词后将其反转
{
    reverse(s.begin(), s.end());
    int n = s.size();
    int idx = 0;
    for (int start = 0; start < n; ++start)
    {
        if (s[start] != ' ')
        {
            if (idx != 0)
                s[idx++] = ' ';
            //循环遍历至单词的末尾
            int end = start;
            while (end < n && s[end] != ' ')//跳过末尾空格
                s[idx++] = s[end++];

            reverse(s.begin() + idx - (end - start), s.begin() + idx); //反转整个单词
            start = end;                                               //更新start，去找下一个单词
        }
    }
    s.erase(s.begin() + idx, s.end());
    return s;
}
int main()
{
    string s = " the sky   is blue";
    cout << reverseWords(s);
}