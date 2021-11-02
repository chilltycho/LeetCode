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
定义函数f(n,m)表示在n个数字中不断删除第m个数字最后剩下的数字。第一步，在n个数字中删除第m个数字。
剩下n-1个数字，再次删除就是在n-1个数字中删除第m个数字，表示为f(n-1,m)。每步删除具有相同形式，
可用递归或动态规划问题解决。但f(n,m)是从0开始，被删除元素为(m-1)%n=k，第二步会从k+1开始，从
第二步不断删除的结果可表示为f'(n-1,m)。有f(n,m)=f'(n-1,m)。
y=f'(n-1,m): k+1 k+2 k+3 ... n-1 0 1 2 ... k-1
x=f(n-1,m):   0   1   2  ... n-k-2 n-k-1 n-k ... n-2
y=(x+k+1)%n, 带入y和x，f'(n-1,m)=(f(n-1,m)+k+1)%n
                               =(f(n-1,m)+(m-1)%n+1)%n
                               =(f(n-1,m)+m)%n
n=1时，f(n,m)=f(1,m)=0
n>1时, f(n,m)=(f(n-1,m)+m)%n
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