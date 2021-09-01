/**
 * 0-n-1排成圆圈，从0开始，每次删除第m个数，求最后剩下的数
*/
#include <bits/stdc++.h>
using namespace std;
int f(int n, int m) // 最后留下元素的序号
{
    if (n == 1)
        return 0;
    int x = f(n - 1, m); // 对n-1个元素，最终留下的元素
    return (m + x) % n;  // 对n个元素，删除的是m%n,
}
int lastRemaining(int n, int m)
{
    return f(n, m);
}

/*
第一步：对输入n,m解为f(n,m)，起点为0，删除的元素是k=(m-1)%n 
第二步：起点是k+1，f(n,m)=f'(n-1,m)
建立f'(n-1,m)和f(n-1,m)之间关系，只有起点不同
f'(n-1,m)或y: k+1, k+2, k+3, ... , n-1,   0,      1, ... k-1
f(n-1,m)或x:   0    1    2 , ... , n-k-2, n-k-1, 
所以f'(n-1,m)=[f(n-1,m)+m]%n
y=(x+k+1)%n=(x+(m-1)%n+1)%n =(x+m)%n, dp[i]=(dp[i-1]+m)%i
*/

int sol_dp(int n, int m)
{
    vector<int> dp(n + 1, 0); // dp[1]=0
    for (int i = 2; i <= n; ++i)
        dp[i] = (dp[i - 1] + m) % i;
    return dp[n];
}

int sol(int n, int m)
{
    int x = 0;
    for (int i = 2; i <= n; ++i)
        x = (x + m) % i;
    return x;
}

int lastRemaining_bru(int n, int m)
{
    deque<int> mq;
    for (int i = 0; i < n; ++i)
        mq.push_back(i);
    int num = 1;
    while (mq.size() > 1)
    {
        auto first = mq.front();
        mq.pop_front();
        if (num % m == 0) // 应该删除的数
        {
            num = 1;
            continue;
        }
        mq.push_back(first);
        ++num;
    }
    return mq.front();
}

int main()
{
    cout << lastRemaining_bru(5, 3) << endl;
}