/*数字n代表生成括号的对数，请设计一个函数，能用于生成所有可能并且有效的括号组合。*/
#include <vector>
#include <iostream>
using namespace std;

vector<string> res;
//curstr当前结果，left剩余左括号，right剩余右括号,做减法
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
    dfs("", n, n);
    return res;
}
/*dp[i]使用i对括号能够生成的组合，i对括号一个组合，在i-1对括号基础上得到
i对括号的一个组合，一定以左括号开始，不一定以右括号结尾。故可枚举新的右括号
可能所处位置，得到所有组合。
枚举方式就是枚举左括号和右括号中间可能的合法括号对数，剩下的合法括号对数在与第一个
左括号配对的右括号右边。
dp[i]="("+dp[可能括号对数]+")"+dp[剩下括号对数] 
可能括号对数+剩下括号对数=i-1 
dp[i]="("+dp[j]+")"+dp[i-j-1]*/
vector<string> generateParenthesis_dp(int n)
{
    if (n == 0)
        return res;
    if (n == 1)
        return {"()"};
    vector<vector<string>> dp(n + 1);
    dp[0] = {""};
    dp[1] = {"()"};
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (auto p : dp[j])
            {
                for (auto q : dp[i - j - 1])
                {
                    string str = "(" + p + ")" + q;
                    dp[i].push_back(str);
                }
            }
        }
    }
    return dp[n];
}

int main()
{
    auto res = generateParenthesis(3);
    for (auto c : res)
        cout << c << ' ';
}