/*给定整数n，将1到n的二进制连接起来，返回连接结果对应的十进制数字对10^9+7取余结果*/
#include <iostream>
using namespace std;
/*当处理到数字i，且[1,i-1]的二进制连接起来对应十进制数为x。
x=x*2^(len(i))+i*/
static constexpr int mod = 1000000007;
int concatenatedBinary(int n)
{
    int ans = 0;
    int shift = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!(i & (i - 1))) //2的整数次幂与减1后位与正好为0
            ++shift;
        ans = ((static_cast<long long>(ans) << shift) + i) % mod;
    }
    return ans;
}

int countBits(int n)
{
    int count = 0;
    while (n)
    {
        n /= 2;
        count++;
    }
    return count;
}

int concatenatedBinary_1(int n)
{
    long long res = 0;
    for (int i = 1; i <= n; i++)
        res = ((res << countBits(i)) + i) % 1000000007;
    return res;
}