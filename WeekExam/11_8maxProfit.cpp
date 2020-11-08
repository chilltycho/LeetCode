//不同颜色球，每个球价值为剩余相同颜色球价值，求取出orders个球的最大价值
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/*从最多数量球取，每次取得剩下的与次大球数量一样多。
[10,8,6,4,2] orders=20  10+9=19
[8,8,6,4,2] orders=18 (8+7)*2=30
[6,6,6,4,2] orders=14 (6+5)*3=33
[4,4,4,4,2] orders=8  (4+3)*4=28
总价格19+30+33+28=110*/
int maxProfit(vector<int> &nums, int orders)
{
    sort(nums.begin(), nums.end(), greater<int>());
    long res = 0, mod = 1000000007;
    size_t start = 0;
    while (orders > 0)
    {
        while (start < nums.size() && nums[start] >= nums[0])
            ++start; //最大数个数
        int next = 0;
        if (start < nums.size())
            next = nums[start]; //次最大数
        long bucks = start, delta = nums[0] - next;
        long rem = bucks * delta; //拿取的球个数
        if (rem > orders)         //拿取球个数大于应拿的个数
        {
            long dec = orders / bucks;
            long al = nums[0] - dec + 1, an = nums[0];
            res += (((al + an) * dec) / 2) * bucks;
            res += (nums[0] - dec) * (orders % bucks);
        }
        else
        {
            long al = next + 1, an = nums[0];
            res += (((al + an) * delta) / 2) * bucks;
            nums[0] = next; //最大数大小=次最大数大小
        }
        orders -= rem;
        res %= mod;
    }
    return res;
}

//二分发查找最后一次卖出时，球的价格x
bool ck(vector<int> &nums, int x, int orders)
{
    int sum = 0;
    for (int i : nums)
    {
        sum += max(i - x, 0);
        if (sum > orders)
            return true;
    }
    return false;
}

int maxProfit_1(vector<int> &nums, int orders)
{
    long l = 0, r = 1e9;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (ck(nums, mid, orders))
            l = mid + 1;
        else
            r = mid;
    }
    //价格为l
    long res = 0, mod = 1e9 + 7;
    for (int i : nums)
    {
        if (i > l)
        {
            res += ((long)(i + l + 1) * (long)(i - l)) >> 1;
            res %= mod;
            orders -= i - l;
        }
    }
    res += (long)l * (long)orders;
    res %= mod;
    return res;
}

int main()
{
    vector<int> vi{2, 8, 4, 10, 6};
    cout << maxProfit(vi, 20) << endl; //110
}