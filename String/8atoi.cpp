// 实现atoi，不合法的输出0，截取到INT_MIN到INT_MAX内
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
int myAtoi(string str)
{
    unsigned long len = str.size();
    int index = 0;
    // 去除前导空格
    while (index < len)
    {
        if (str[index] != ' ')
            break;
        ++index;
    }
    if (index == len)
        return 0;
    int sign = 1;
    if (str[index] == '+')
        ++index;
    else if (str[index] == '-')
    {
        ++index;
        sign = -1;
    }

    int res = 0;
    while (index < len)
    {
        char cur = str[index];
        if (cur < '0' || cur > '9')
            break;
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (cur - '0') > INT_MAX % 10))
            return INT_MAX;
        if (res < INT_MIN / 10 || (res == INT_MIN / 10 && (cur - '0') > -(INT_MIN % 10)))
            return INT_MIN;
        res = res * 10 + sign * (cur - '0');
        ++index;
    }
    return res;
}