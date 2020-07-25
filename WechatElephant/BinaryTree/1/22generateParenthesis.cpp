/*数字n代表生成括号的对数，请设计一个函数，能用于生成所有可能并且有效的括号组合。*/
#include <vector>
#include <iostream>
using namespace std;

vector<string> res;
//curstr当前结果，left剩余左括号，right剩余右括号
void dfs(string curstr, int left, int right) //dfs
{
    if (left == 0 && right == 0)
    {
        res.push_back(curstr);
        return;
    }
    if (left > right) //剩余左括号大于右括号，错误结果
    {
        return;
    }
    if (left > 0)
    {
        curstr += "(";
        dfs(curstr, left - 1, right);
        curstr.pop_back();
    }
    if (right > 0)
    {
        curstr += ")";
        dfs(curstr, left, right - 1);
        curstr.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    dfs("", n, n);
    return res;
}
int main()
{
    auto res = generateParenthesis(3);
    for (auto c : res)
        cout << c << ' ';
}