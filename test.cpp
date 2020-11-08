#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

int sumIt(LL begin, LL end)
{
    return (begin + end) * (end - begin + 1) / 2 % 1000000007;
}

int maxProfit(vector<int> &inventory, int orders)
{
    sort(inventory.begin(), inventory.end(), [](int &a, int &b) { return a > b; });
    LL old = 0;
    LL fre = 0;
    if (inventory.size() == 1)
        return sumIt(inventory[0] - orders, inventory[0]) % 1000000007;
    for (int j = 0; j < inventory.size() - 1; j++)
    {
        if (orders > 0)
        {
            if (inventory[j] >= inventory[j + 1])
            {
                auto intervals = min(inventory[j] - inventory[j + 1] + 1, orders);
                fre = old + sumIt(inventory[j] - intervals + 1, inventory[j]) % 1000000007;
                old = fre;
                inventory[j] -= intervals;
                orders -= intervals;
            }
        }
        else
            break;
    }
    return fre;
}

int main()
{
    vector<int> vi{2, 8, 4, 6, 10};
    cout << maxProfit(vi, 20);
}