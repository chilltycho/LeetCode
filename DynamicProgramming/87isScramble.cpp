/*给定字符串s1,可将其递归的分割为两个非空子字符串，表示为二叉树。
挑选一个非叶节点，交换两个子节点。称为扰乱，判断s1是否为s2扰乱子节点*/
#include <iostream>
#include <vector>
using namespace std;
//dp[i][j][len]表示从字符串S第i个字符能否变换为T地j开始的长度len字符串
bool isScramble(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    if (n != m)
        return false;
    vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dp[i][j][1] = s1[i] == s2[j]; //对单个字符
    }
    for (int len = 2; len <= n; len++)
    {
        //枚举S中起点位置
        for (int i = 0; i <= n - len; i++)
        {
            //枚举T中的起点位置
            for (int j = 0; j <= n - len; j++)
            {
                //枚举划分位置
                for (int k = 1; k <= len - 1; k++)
                {
                    //第一种情况:S1->T1, S2->T2
                    if (dp[i][j][k] && dp[i + k][j + k][len - k])
                    {
                        dp[i][j][len] = true;
                        break;
                    }
                    //第二种情况:S1->T2,S2->T1 S1起点i
                    if (dp[i][j + len - k][k] && dp[i + k][j][len - k])
                    {
                        dp[i][j][len] = true;
                        break;
                    }
                }
            }
        }
    }
    return dp[0][0][n];
}

int main()
{

}