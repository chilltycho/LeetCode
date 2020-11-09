//不用乘除、循环、判断计算1+2+..+n
#include <iostream>
#include <cassert>
using namespace std;
int sumNums(int n)
{
    n && (n += sumNums(n - 1));
    return n;
}
//用加法，位运算计算相乘
int quickMulti(int A, int B)
{
    int ans = 0;
    for (; B; B >>= 1)
    {
        if (B & 1)
            ans += A;
        A <<= 1;
    }
    return ans;
}
//n范围[1,10000]，n二进制最多不会超过14位，手动展开14次
int sumNums_1(int n)
{
    int ans=0,A=n,B=n+1;
    (B&1)&&(ans+=A);
    A<<=1;
    B>>=1;
    (B&1)&&(ans+=A);
    A<<=1;
    B>>=1;
    (B&1)&&(ans+=A);
    A<<=1;
    B>>=1;
    (B&1)&&(ans+=A);
    A<<=1;
    B>>=1;
    (B&1)&&(ans+=A);
    A<<=1;
    B>>=1;
    (B&1)&&(ans+=A);
    A<<=1;
    B>>=1;
    (B&1)&&(ans+=A);
    A<<=1;
    B>>=1;
    (B&1)&&(ans+=A);
    A<<=1;
    B>>=1;
    (B&1)&&(ans+=A);
    A<<=1;
    B>>=1;
    (B&1)&&(ans+=A);
    A<<=1;
    B>>=1;
    (B&1)&&(ans+=A);
    A<<=1;
    B>>=1;
    (B&1)&&(ans+=A);
    A<<=1;
    B>>=1;
    (B&1)&&(ans+=A);
    A<<=1;
    B>>=1;
    (B&1)&&(ans+=A);
    A<<=1;
    B>>=1;
    return ans>>1;
}

int main()
{
    cout << quickMulti(2, 3) << endl;
}