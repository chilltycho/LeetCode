/*a先拿，a[i],b[i]表示a,b认为第i个石子价值。所有石子取完后，得分较高的取胜*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*假设有两石头a,b价值分别为a1,a2,b1,b2。
第一种方案a与b价值差：c1=a1-b2
第二种方案a与b价值差：c2=a2-b1
最优取决于两方案价值差:c=c1-c2=(a1+b1)-(a2+b2)
c>0方案1最优，c==0两方案相同，c<0方案2最优*/
int stoneGameVi(vector<int> &aliceValues, vector<int> &bobValues)
{
    vector<int> a = aliceValues;
    vector<int> b = bobValues;
    vector<pair<int, int>> mp;
    int n = aliceValues.size();
    for (int i = 0; i < n; i++)
    {
        int dis = a[i] + b[i];
        mp.emplace_back(dis, i); //记录价值和及下标
    }
    sort(mp.rbegin(), mp.rend()); //排序，每次取价值大的
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            sum1 += a[mp[i].second];
        else
            sum2 += b[mp[i].second];
    }
    if (sum1 == sum2)
        return 0;
    else if (sum1 > sum2)
        return 1;
    else
        return -1;
}