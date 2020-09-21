//计算并返回x的平方根,结果只保留整数部分
#include <iostream>
#include <cassert>
using namespace std;

//一个数的平方根最多不会超过它的一半
int mySqrt_bi(int x)
{
    if (x == 0 || x == 1)
        return x;
    int left = 1;
    int right = x / 2;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int cur = x / mid;
        if (cur > mid)
            left = mid + 1;
        else if (cur < mid)
            right = mid - 1;
        else
            return mid;
    }
    return right;
}

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