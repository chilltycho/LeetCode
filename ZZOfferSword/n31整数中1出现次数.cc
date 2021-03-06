/**
 * f(n)表示1-n中1出现次数
 * n=1234, high=1, pow=1000, last=234
 * 分为两部分：1-999和1000-1234
 * 1-999为f(pow-1) 
 * 1000-1234: 千位为1：234(last)+1 和 其他位为1 f(234)
 * 全部：f(pow-1)+last+1+f(last)
 * 
 * n=3234 hight=3,pow=1000,last=234
 * 分为两部分:1-999,1000-1999,2000-2999和3000-3234
 * 1-999为f(999), 1000-1999为pow+f(pow-1)
 * 2000-2999为f(pow-1)
 * 3000-3234为f(last)
 * 全部：pow+high*f(pow-1)+f(last)
*/
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int f(int n)
{
    if (n <= 0)
        return 0;
    string s = to_string(n);
    int high = s[0] - '0';
    int po = pow(10, s.size() - 1);
    int last = n - high * po;
    if (high == 1)
        return f(po - 1) + last + 1 + f(last);
    else
        return po + high * f(po - 1) + f(last);
}
int count1(int n)
{
    return f(n);
}

int main()
{
    cout << count1(1234) << endl;
}