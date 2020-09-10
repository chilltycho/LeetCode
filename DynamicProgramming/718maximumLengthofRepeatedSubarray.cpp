/*
给定两个数组A和B，返回两个数组中公共的，长度最长的子数组的长度
A:[1,2,3,2,1] B:[3,2,1,4,7]
子数组表示必须连续，输出[3,2,1]长度3

1.子问题定义：f(i,j)表示s[0..i)和[0..j)以最后一个元素结尾的最长公共子数组
2.状态转移：
f(i,j)=f(i-1,j-1)+1 if s[i-1]==t[j-1]
f(i,j)=0 if(s[i-1]!=t[j-1])
*/
#include <iostream>
#include <vector>
using namespace std;
int findLength(vector<int> &A, vector<int> &B) //动态规划
{
    if (A.empty() || B.empty())
        return 0;
    int m = A.size();
    int n = B.size();
    int dp[m + 1][n + 1];
    int res = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 0;
            }
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

int findLength_violence(vector<int> &A, vector<int> &B) //暴力法O(n^3)
{
    if (A.empty() || B.empty())
        return 0;
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            int k = 0;
            while (A[i + k] == B[j + k])
                k++;
            ans = max(ans, k);
        }
    }
    return ans;
}

int maxLength(vector<int> &A, vector<int> &B, int addA, int addB, int len)
{
    int ret = 0, k = 0;
    for (int i = 0; i < len; i++)
    {
        if (A[addA + i] == B[addB + i])
            k++;
        else
            k = 0;
        ret = max(ret, k);
    }
    return ret;
}

int findLength_slide(vector<int> &A, vector<int> &B) //滑动窗口，先对齐，再比较
{
    if (A.empty() || B.empty())
        return 0;
    auto n = A.size(), m = B.size();
    int ret = 0;
    for (int i = 0; i < n; i++) //B不动，滑动A
    {
        auto len = min(m, n - i);
        auto maxlen = maxLength(A, B, i, 0, len);
        ret = max(ret, maxlen);
    }
    for (int i = 0; i < m; i++) //A不动，滑动B
    {
        auto len = min(n, m - i);
        auto maxlen = maxLength(A, B, 0, i, len);
        ret = max(ret, maxlen);
    }
    return ret;
}

int main()
{
    vector<int> A{1, 2, 3, 2, 1};
    vector<int> B{3, 2, 1, 47};
    cout << findLength(A, B) << endl;
    cout << findLength_violence(A, B) << endl;
}