/*石子游戏中a，b轮流，每个玩家可从行中移除最左边或最右边石头，获得剩余石头之和的得分。
没有石头可移除时，得分较高者获胜。b总是输，决定减少得分差值。a目标是扩大得分差值。
若a，b发挥最佳水平，返回得分差值*/
#include <iostream>
#include <vector>
using namespace std;
/*dp[i][j]为区间[i,j]想要的结果：先手总分-后手总分。若dp[i][j]区间当前是
b操作，b得分一定最大。去掉stones[i]后当前分数为sum(stones[i+1],stones[j])
*/
int stoneGameVII(vector<int> &stones)
{
    vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), 0));
    vector<int> sums(stones.size() + 1, 0);
    for (int i = 0; i < stones.size(); i++)
        sum[i + 1] = sum[i] + stones[i];
    for (int i = dp.size() - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < dp[i].size(); j++)
            dp[i][j] = max(sums[j + 1] - sums[i + 1] - dp[i + 1][j], sums[j] - sums[i] - dp[i][j - 1]);
    }
    return dp.front().back();
}

int main()
{
    vector<int> vi{7, 90, 5, 1, 100, 10, 10, 2};
    //vector<int> vi1{5, 3, 1, 4, 2};
    //cout << stoneGameVII(vi1) << endl;
    auto rt = calWindowSum(0, 7, 3, vi);
    cout << rt.l << ' ' << rt.r << ' ' << rt.sum << endl;
}