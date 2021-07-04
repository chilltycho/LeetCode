//给定环字符串，12点方向为ring[0]，顺时针排列。每次匹配后需按下按钮，再匹配下一个。求最少步数
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
/*第一个需找的字母是a，字母a索引为1和8：dp[0][1] = 1+1, dp[0][8]=2+1
  第二个需找的字母是b，索引为3：dp[1][3] = min(dp[0][1]+2+1,dp[0][8]+5+1)*/
int findRotateSteps(string ring, string key)
{
    int n = ring.size(), m = key.size();
    vector<int> pos[26];
    for (int i = 0; i < n; i++)
        pos[ring[i] - 'a'].push_back(i);
    int dp[m][n];
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (auto &i : pos[key[0] - 'a']) //先key匹配第一个字符
        dp[0][i] = min(i, n - i) + 1;
    for (int i = 1; i < m; i++)
    {
        for (auto &j : pos[key[i] - 'a'])
        {
            for (auto &k : pos[key[i - 1] - 'a'])
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
        }
    }
    return *min_element(dp[m - 1], dp[m - 1] + n);
}

int calc(int len, int a, int b)
{
    return min((len + a - b) % len, (len + b - a) % len);
}

int findRotateSteps_1(string ring, string key)
{
    vector<int> pos[26];
    for (int i = 0; i < ring.size(); ++i)
        pos[ring[i] - 'a'].push_back(i);
    // dp[i][j], i为需找key的第i个元素，j为环当前位置
    vector<vector<int>> dp(key.size(), vector<int>(ring.size(), INT_MAX));
    for (int i = 0; i < key.size(); ++i)
    {
        for (int j : pos[key[i] - 'a'])         // key[i]在环中可能位置
        {
            if (i == 0)
            {
                dp[i][j] = min(dp[i][j], 0 + calc(ring.size(), 0, j) + 1);
                continue;
            }
            for (int k : pos[key[i - 1] - 'a']) // key[i-1]在环中位置
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + calc(ring.size(), k, j) + 1);
        }
    }
    return *min_element(dp.back().begin(), dp.back().end());
}

int main()
{
    cout << findRotateSteps("godding", "gd"); //4
}
