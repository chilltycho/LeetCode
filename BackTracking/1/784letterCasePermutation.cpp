/*给定一个字符串S，将S中每个字母转变大小写，可得到一个新字符串，返回所有可能的字符串集合
输入:"a1b2" 输出：["a1b2","a1B2","A1b2","A1B2"]
输入："3z4" 输出：["3z4","3Z4"]*/
#include <vector>
#include <iostream>
#include <cctype>
using namespace std;
vector<string> res;
//使用异或转换字母大小写,大写字母与对应小写字母ASCII差为32,2^5
//若是小写,减去32,若是大写,加上32.合并为对字符的异或操作
void dfs(string S, int index)
{
    if (S.size() == index)
    {
        res.push_back(S);
        return;
    }
    //未修改时
    dfs(S, index + 1);
    //修改当前字母时
    if (isalpha(S[index]))
    {
        S[index] = S[index] ^ 32;
        dfs(S, index + 1);
    }
}
vector<string> letterCasePermutation(string S)
{
    dfs(S, 0);
    return res;
}

vector<string> letterCasePermutation_ite(string S)
{
    vector<string> ans{S};
    for (int i = 0; i < S.size(); i++)
    {
        if (isalpha(S[i]))
        {
            for (int j = ans.size() - 1; j >= 0; j--)
            {
                ans.push_back(ans[j]);
                ans[j][i] ^= 32;
            }
        }
    }
    return ans;
}

void dfs_1(string s, int i, vector<string>& l)
{
    for (; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 'a' + 'A';
            dfs_1(s, i + 1, l);
            s[i] = s[i] - 'A' + 'a';
        }
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] - 'A' + 'a';
            dfs_1(s, i + 1, l);
            s[i] = s[i] - 'a' + 'A';
        }
    }
    l.push_back(s);
}

vector<string> letterCasePermutation_1(string S)
{
    dfs_1(S, 0, res);
    return res;
}

int main()
{
    string s = "ab";
    auto res = letterCasePermutation_1(s);
    for (auto c : res)
        cout << c << ' ';
}