#include<vector>
#include<string>
#include <cassert>
using namespace std;
//对两个单词word1,word2。计算将word1转换为word2所使用的最少操作数。可进行操作：1.插入字符 2.删除字符 3.替换字符
/*
1.定义子问题为s[0..i)和t[0..j)的编辑距离
2.子问题递推关系：
三种方案：(1)删除s[i-1],计算s[0..i-1)和t[0..j)的编辑距离（去掉s最后一个字符）
         (2)插入t[j-1],计算s[0..i)和t[0..j-1)的编辑距离（去掉t的最后一个字符）
         (3)将s[i-1]替换为t[j-1]，计算s[0..i-1)和t[0..j-1)的编辑距离（去掉s和t最后一个字符）*/
int minDistance(string word1, string word2)
{
    const auto m = word1.size();
    const auto n = word2.size();
    
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j; //添加j个
            else if (j == 0)
                dp[i][j] = i; //删除i个
            else
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), 
                                 dp[i - 1][j - 1]);
                }
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string word1 = "intention", word2 = "execution";
    assert(5 == minDistance(word1, word2));
    string w1 = "horse", w2 = "ros"; //将'h'替换为'r'，删除'r','e'
    assert(3 == minDistance(w1, w2));
}