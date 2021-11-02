/**
 * 因子只包括2，3，5的数为丑数，求第n个。1也是
 * num2={1*2,2*2,3*2,4*2,5*2,6*2,8*2...}
 * num3={1*3.2*3.3*3,4*3,5*3,6*3,8*3...}
 * num5={1*5.2*5.3*5,4*5,5*5,6*5,8*5...}
 * 合并三个序列并去重
*/
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int nthUglyNumber(int n)
{
    if (n <= 0)
        return 0;
    vector<int> dp(n, 0);
    dp[0] = 1;
    int p2 = 0, p3 = 0, p5 = 0; // 表示前p2个数已经乘过2
    for (int i = 1; i < n; i++)
    {
        int n2 = dp[p2] * 2, n3 = dp[p3] * 3, n5 = dp[p5] * 5;
        dp[i] = min(min(n2, n3), n5);
        // 不使用if else来去重复
        if (dp[i] == n2)
            p2++;
        if (dp[i] == n3)
            p3++;
        if (dp[i] == n5)
            p5++;
    }
    return dp[n - 1];
}

int sol1(int n)
{
    priority_queue<long, vector<long>, greater<long>> pq;
    pq.push(1);
    unordered_set<long> st;
    long x = 0;
    vector<long> tmp{2, 3, 5};
    for (int i = 0; i < n; ++i)
    {
        x = pq.top();
        pq.pop();
        for (auto c : tmp)
        {
            if (st.find(c * x) == st.end())
            {
                pq.push(c * x);
                st.insert(c * x);
            }
        }
    }
    return x;
}
int main()
{
    cout << nthUglyNumber(7) << endl;
}