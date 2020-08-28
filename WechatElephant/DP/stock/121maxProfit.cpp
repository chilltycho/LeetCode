#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
//股票最多交易一次
int maxProfit(vector<int> &prices)
{
    if (prices.empty())
        return 0;
    const int n = prices.size();
    vector<int> s1(n + 1), s2(n + 1);
    s1[0] = INT_MIN; //持有状态，由于购买可导致负资产
    s2[0] = 0;       //未持有状态，有效值不应低于0（不买不卖）
    for (int k = 1; k <= n; k++)
    {
        s1[k] = max(s1[k - 1], -prices[k - 1]);
        s2[k] = max(s2[k - 1], s1[k - 1] + prices[k - 1]);
    }
    return max(0, s2[n]);
}

int main()
{
    vector<int> v1{7, 1, 5, 3, 6, 4}; //第2天(1)买入，第5天(6)卖出。利润为5
    assert(5 == maxProfit(v1));
    vector<int> v2{7, 6, 5, 3, 1}; //不买入，利润为0
    assert(0 == maxProfit(v2));
}