//给定两整数，要求不用乘法，除法和mod运算符。返回截去小数点的商
#include <iostream>
#include <climits>
using namespace std;
/*11除以3,11比3大，让3翻倍，11比6大，让6翻倍得12,
则结果在2和4之间。
*/
int divm(long a, long b)
{
    if (a < b)
        return 0;
    long count = 1;
    long tb = b;
    while (tb + tb <= a)
    {
        count = count + count;
        tb = tb + tb;
    }
    return count + divm(a - tb, b);
}
int divide(int dividend, int divisor)
{
    if (dividend == 0)
        return 0;
    if (divisor == 1)
        return dividend;
    if (divisor == -1)
    {
        if (dividend > INT_MIN)
            return -dividend;
        else
            return INT_MAX;
    }
    long a = dividend;
    long b = divisor;
    int sign = 1;
    if ((a > 0 && b < 0) || (a < 0 && b > 0))
        sign = -1;
    a = a > 0 ? a : -a;
    b = b > 0 ? b : -b;
    long res = divm(a, b);
    if (sign > 0)
        return res > INT_MAX ? INT_MAX : res;
    else
        return -res;
}

int main()
{
    cout << divide(11, 3) << endl;
}