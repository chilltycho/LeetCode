#include <string>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int strToInt(string str)
{
    int i = 0;
    //1. 过滤掉前置空格，直到不为空格的字符。
    while (i < str.size() && str[i] == ' ')
    {
        ++i;
    }
    if (i >= str.size())
    {
        return 0;
    }
    bool sign = false;
    //提取+，-符号。
    if (str[i] == '-')
    {
        sign = true;
        ++i;
    }
    else if (str[i] == '+')
    {
        ++i;
    }
    //
    if (i >= str.size())
    {
        return 0;
    }
    if (!isdigit(str[i]))
    {
        return 0;
    }
    long long ans = 0;
    //提取整数部分。累加过程中，如果正数 > INT_MAX时，返回INT_MAX. 如果负数 < INT_MIN时，返回INT_MIN.
    while (i < str.size() && isdigit(str[i]))
    {
        ans = ans * 10 + (str[i] - '0');
        if (!sign && ans > INT_MAX)
        {
            return INT_MAX;
        }
        else if (sign && -ans < INT_MIN)
        {
            return INT_MIN;
        }
        ++i;
    }
    return sign ? -ans : ans;
}

int main()
{
    cout << strToInt("11111") << endl;
}