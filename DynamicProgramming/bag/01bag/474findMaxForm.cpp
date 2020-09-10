//使用给定m个0和n个1，找到能拼出存在于数组中的字符串的最大数量
#include <vector>
#include <cassert>
#include <string>
using namespace std;
/*dp[i][j][k]表示输入字符串在子区间[0,i]能使用j个0，k个1的字符串的最大数量
dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-zeros][k-ones]+1)*/
pair<int, int> countZeroAndOne(string str)
{
    pair<int, int> cnt{0, 0};
    for (auto c : str)
    {
        if (c == '0')
            cnt.first++;
        else
            cnt.second++;
    }
    return cnt;
}
int findMaxForm(vector<string> &strs, int m, int n)
{
    if (strs.empty())
        return 0;
    auto len = strs.size();
    vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    for (int i = 1; i <= len; i++)
    {
        auto cnt = countZeroAndOne(strs[i - 1]);
        auto zeros = cnt.first;
        auto ones = cnt.second;
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                if (j >= zeros && k >= ones)
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                else
                    dp[i][j][k] = dp[i - 1][j][k];
            }
        }
    }
    return dp[len][m][n];
}
//优化空间，仅使用上一行数据
int findMaxForm_sp(vector<string> &strs, int m, int n)
{
    if (strs.empty())
        return 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = 0;
    for (auto s : strs)
    {
        auto cnt = countZeroAndOne(s);
        auto zeros = cnt.first;
        auto ones = cnt.second;
        for (int i = m; i >= zeros; i--)
        {
            for (int j = n; j >= ones; j--)
            {
                dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    vector<string> v1{"10", "0001", "111001", "1", "0"};
    assert(4 == findMaxForm(v1, 5, 3)); //5个0，3个1可拼出"10","0001","1","0"
    vector<string> v2{"10", "0", "1"};
    assert(2 == findMaxForm_sp(v2, 1, 1)); //可拼出"10"，但无剩余。好的选择是拼出"0"和"1"
}