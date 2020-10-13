/*给定一个字符串S，将S中每个字母转变大小写，可得到一个新字符串，返回所有可能的字符串集合
输入:"a1b2" 输出：["a1b2","a1B2","A1b2","A1B2"]
输入："3z4" 输出：["3z4","3Z4"]*/
#include <vector>
#include <iostream>
using namespace std;

vector<string> res;
void dfs(string s, int i)
{
    for(;i<s.size();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            s[i]=s[i]-'a'+'A';
            dfs(s,i+1);
            s[i]=s[i]-'A'+'a';
        }
        if(s[i]>='A'&&s[i]<='Z')
        {
            s[i]=s[i]-'A'+'a';
            dfs(s,i+1);
            s[i]=s[i]-'a'+'A';
        }
    }
    res.push_back(s);
}

vector<string> letterCasePermutation(string S)
{
    string temp = "";
    dfs(S, 0);
    return res;
}

int main()
{
    string s = "ab";
    auto res = letterCasePermutation(s);
    for (auto c : res)
        cout << c << ' ';
}