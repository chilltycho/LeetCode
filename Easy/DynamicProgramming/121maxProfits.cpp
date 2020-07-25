#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            ans = max(ans, prices[j] - prices[i]);
    }
    return ans;
}

int maxProfit_1(vector<int> &prices)
{
    int minprice = INT_MAX, maxprofit = 0;
    for (int price : prices)
    {
        maxprofit = max(maxprofit, price - minprice);
        minprice = min(price, minprice);
    }
    return maxprofit;
}

int main()
{
    vector<int> vi{7, 1, 5, 3, 6, 4};
    cout << maxProfit(vi) << endl;
    cout << maxProfit_1(vi) << endl;
}