//将绳长n剪成m段(n>1,m>1)使得m段长度乘积最大
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

int cuttingRope(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++) //拆分出的第一个整数,剩余i-j可拆(dp[i-j]),可不拆(i-j)
        {
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
    }
    return dp[n];
}
int cuttingRope(int n)
{
    if(n==2)
        return 1;
    if(n==3)
        return 2;
    if(n==4)
        return 4;
    long res=1;
    while(n>4)
    {
        res*=3;
        if(res>=1000000007)
            res-=1000000007;
        n-=3;
    }
    return (res*n)%1000000007;
}

int main()
{
    assert(1 == cuttingRope(2));
    assert(36 == cuttingRope(10)); //3+3+4
    cout << cuttingRope(120) << endl;
}