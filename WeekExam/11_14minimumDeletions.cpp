//对只包含'a'和'b'的字符串，删除s中任意数目字符，使得所有a在b左边,求最小删除数目
#include <cassert>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
//dp[i][0]表示以a结尾，dp[i][1]表示以b结尾
int minimumDeletions(string s)
{
    int len = s.size();
    int dp[len + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= len; i++)
    {
        if (s[i - 1] == 'a')//当前位为'a'
        {
            dp[i][0] = dp[i - 1][0];//a结尾，无需删除
            dp[i][1] = dp[i - 1][1] + 1;//b结尾，a->b操作数+1
        }
        else //当前位为'b'
        {
            dp[i][0] = dp[i - 1][0] + 1;//'a'结尾，b->a，操作数+1
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);//‘b’结尾，取前一个a/b结尾最小操作数
        }
    }
    return min(dp[len][0], dp[len][1]);
}

int main()
{
    assert(2 == minimumDeletions("aababbab"));
    assert(2 == minimumDeletions("bbaaaaabb"));
}