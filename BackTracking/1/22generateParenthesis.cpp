/*数字n代表生成括号的对数，请设计一个函数，能用于生成所有可能并且有效的括号组合。*/
#include <vector>
#include <iostream>
using namespace std;

string path;
vector<string> res;
void dfs(int l, int r)
{
    if (l == 0 && r == 0)
    {
        res.push_back(path);
        return;
    }
    if (l > r)
        return;
    if (l > 0)
    {
        path += "(";
        dfs(l - 1, r);
        path.pop_back();
    }
    if (r > 0)
    {
        path += ")";
        dfs(l, r - 1);
        path.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    dfs(n, n);
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