//计算并返回x的平方根,结果只保留整数部分
#include <iostream>
#include <cassert>
using namespace std;

//一个数的平方根最多不会超过它的一半
int mySqrt_bi(int x)
{
    if (x == 0 || x == 1)
        return x;
    int l = 1, r = x / 2; //区间[l,r]
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (m > x / m)
            r = m - 1;
        else
            l = m;
    }
    return l;
}
/*
不断用(x, f(x))切线来逼近x^2-a=0的根。x-f(x)/(2x)比x更接近解。代入f(x)=x^2-a
得到x-(x^2-a)/(2x)，即(x+a/x)/2
*/
int mySqrt_newton(int x)
{
    if (x == 0 || x == 1)
        return x;
    double cur = 1;
    while (true)
    {
        double pre = cur;
        cur = (cur + x / cur) / 2;
        if (abs(cur - pre) < 0.000001)
            return (int)cur;
    }
}

int main()
{
    assert(2 == mySqrt_newton(4));
    assert(2 == mySqrt_newton(8));
}