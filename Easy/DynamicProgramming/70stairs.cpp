#include <iostream>
#include<cmath>
using namespace std;
//爬楼梯，每次可跨1或2层，求爬n级楼梯时有多少种爬法
int climb_Stairs(int i, int n)
{
    if (i > n)
        return 0;
    if (i == n)
        return 1;
    return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
}

int climbStairs(int n)
{
    return climb_Stairs(0, n);
}

int climb_Stairs_1(int i, int n, int memo[])
{
    if (i > n)
        return 0;
    if (i == n)
        return 1;
    if (memo[i] > 0)
        return memo[i];
    memo[i] = climb_Stairs_1(i + 1, n, memo) + climb_Stairs_1(i + 2, n, memo);
    return memo[i];
}

int climbStairs_1(int n)
{
    int *memo = new int[n + 1]{0};
    return climb_Stairs_1(0, n, memo);
}

//斐波那契 dp[n]=dp[n-1]+dp[n-2]且dp[0]=dp[1]=1
int climbfib(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    return climbfib(n - 1) + climbfib(n - 2);
}

int climb_ite(int a, int b, int count)
{
    if (count == 0)
        return b;
    return climb_ite(a + b, a, --count);
}
int climb(int n)
{
    return climb_ite(1, 1, n);
}

int fib(int n)
{
    double sqrt_5=sqrt(5);
    double fibn=pow((1+sqrt_5)/2,n+1)-pow((1-sqrt_5)/2,n+1);
    return (int)(fibn/sqrt_5);
}


int main()
{
    cout << climbStairs_1(6) << endl;
    cout << fib(6) << endl;
}