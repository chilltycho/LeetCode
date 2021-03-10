//区间表示视频段，返回能将剪辑后内容拼接成覆盖整个运动过程的片段[0,T]的最少片段数，若无法完成，返回-1
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

int videoStitching(vector<vector<int>> &clips, int T)
{
    //dp[i]表示将区间[0,i)覆盖所需最少子区间数量
    vector<int> dp(T + 1, INT32_MAX - 1);
    dp[0] = 0;
    for (int i = 1; i <= T; i++)
    {
        for (auto &it : clips)
        {
            if (it[0] < i && i <= it[1])
                //dp[i]=min(dp[aj])+1 (aj<i<bj)
                dp[i] = min(dp[i], dp[it[0]] + 1);
        }
    }
    return dp[T] == INT32_MAX - 1 ? -1 : dp[T];
}

//贪心，对所有左端点相同的子区间，右端点越远越有利
int videoStitching(vector<vector<int>> &clips, int T)
{
    vector<int> maxn(T);
    int last = 0, ret = 0, pre = 0;
    //记录以左端点的子区间中最远的右端点
    for (auto &it : clips)
        if (it[0] < T)
            maxn[it[0]] = max(maxn[it[0]], it[1]);
    for (int i = 0; i < T; i++)
    {
        last = max(last, maxn[i]);// 当前能到达最远距离
        if (i == last)
            return -1;
        if (i == pre)// 越过一个子区间
        {
            ret++;
            pre = last;
        }
    }
    return ret;
}
int main()
{
    vector<vector<int>> clips{{0, 2}, {4, 8}};
    vector<vector<int>> clips1{
        {0, 1},
        {6, 8},
        {0, 2},
        {5, 6},
        {0, 4},
        {0, 3},
        {6, 7},
        {1, 3},
        {4, 7},
        {1, 4},
        {2, 5},
        {2, 6},
        {3, 4},
        {4, 5},
        {5, 7},
        {6, 9}};
    cout << videoStitching(clips1, 9) << endl; //3 [0,2] [2,8] [8,10]
}