#include<iostream>
#include<vector>
using namespace std;
/*
打劫农舍问题：每个房子内有一定现金，不能头相邻两间，求能偷最大金额。
1。定义子问题：子问题和原问题相似但规模更小。
假设房子总数为n，则最大金额f(n)，子问题为从k间f(k)。k=n实际为原问题。f(k)可由f(k-1),f(k-2)解出
2.写出子问题递推关系：假设n个房子金额H0,H1,...Hn，则偷k个房子有两种偷法，偷前k-1个f(k-1)或者偷第k-1个H(k-1)+f(k-2)
base case为f(0)=0,f(1)=H(0)
3.确定dp数组计算顺序：一般可使用dp数组，称为子问题数组，每个元素对应一个子问题
*/
int rob(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int N = nums.size();
    int dp[N + 1]{0};
    dp[0] = 0;
    dp[1] = nums[0];
    for (int k = 2; k <= N; k++)
    {
        dp[k] = max(dp[k - 1], dp[k - 2] + nums[k - 1]);
    }
    return dp[N];
}
//空间优化
int rob_1(vector<int> &nums)
{
    int prev = 0, curr = 0; //开始时curr表示dp[k-1],prev表示dp[k-2]
    for (int i : nums)
    {
        int temp = max(curr, prev + i); //dp[k]=max(dp[k-1],dp[k-2]+i)
        prev = curr;
        curr = temp;
    }
    return curr;
}
/*二维动态规划，求两个字符串的最长公共序列
1.定义子问题：原问题为字符串s和t的最长公共序列
子问题可缩小s或t规模：变成s的前i个和t的前j个 f(i,j)
2.写出子问题的递归关系：最简单的是看当前子问题和前一个子问题的关系
f(i,j)表示s[0..i]和t[0..j]的最长公共子序列 可比较s[i-1]和t[j-1] 
出现两种情况，相等或不相等，若相等则直接删去s或t末尾一个字符再比较。
f(i,j)=f(i-1,j-1) if s[i-1]==t[j-1]  
f(i,j)=max(f(i-1,j),f(i,j-1)) ifs[i-1]!=t[j-1]
3.确定dp数组的计算顺序
dp数组大小：0<=i<=m,0<=j<=m故大小为m*n
base case和源问题在dp数组中位置
dp数组中子问题依赖方向：dp[i][j]依赖于f[i-1,j] f[i,j-1] f[i-1,j-1]故为从左到右、从上到下
*/
int longestCommonSubsequences(string s, string t)
{
    if (s.empty() || t.empty())
        return 0;
    int m = s.length();
    int n = t.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0; //base case
            else
            { //状态转移方程
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

//最优解与最值，上面方法仅求出最值，为求出如何做达到最值。

vector<int> rob_backup(vector<int> &nums)
{
    int n = nums.size();
    int *dp = new int[n + 1];
    vector<int> back(n + 1, 0);
    dp[0] = 0, dp[1] = nums[0];
    back[1] = -2; //若back[k]=-1表示dp[k]由dp[k-1]计算而来，若back[k]=-2表示dp[k]由dp[k-2]计算而来
    for (int k = 2; k <= n; k++)
    {
        if (dp[k - 1] >= dp[k - 2] + nums[k - 1])
        {
            dp[k] = dp[k - 1];
            back[k] = -1;
        }
        else
        {
            dp[k] = dp[k - 2] + nums[k - 1];
            back[k] = -2;
        }
    }
    vector<int> res;
    int k = n;
    while (k > 0)
    {
        if (back[k] == -2)
        {
            res.push_back(k - 1);
        }
        k = k + back[k];
    }
    delete[] dp;
    return res;
}
int main()
{
    vector<int> nums{2, 7, 9, 3, 1};
    auto res = rob_backup(nums);
    for (auto c : res)
        cout << c << ' ';
    cout << endl;
    string s = "abcde", t = "ace";
    cout << longestCommonSubsequences(s, t);
}