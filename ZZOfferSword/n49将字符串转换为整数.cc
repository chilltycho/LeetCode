#include <string>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int strToInt(string str)
{
    size_t i;
    int isPositive = 3;
    // 找到第一个为正号、负号、或数字的位置
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
            continue;
        else if (str[i] >= '0' && str[i] <= '9')
            break;
        else if (str[i] == '-')
        {
            isPositive = 0;
            break;
        }
        else if (str[i] == '+')
        {
            isPositive = 1;
            break;
        }
        else
            return 0;
    }
    // 下标越界
    if (i == str.size())
        return 0;
    int ans = 0;
    size_t j;
    // 正数
    if (isPositive != 0)
    {
        j = isPositive == 1 ? i + 1 : i;
        while (j < str.size() && '0' <= str[j] && str[j] <= '9')
        {
            if ((long)ans * 10 > INT_MAX)
                return INT_MAX;
            else
                ans = ans * 10;
            if ((long)ans + str[j] - '0' > INT_MAX)
                return INT_MAX;
            else
                ans += str[j] - '0';
            j++;
        }
    }
    // 负数
    else
    {
        j = i + 1;
        while (j < str.size() && '0' <= str[j] && str[j] <= '9')
        {
            if ((long)ans * 10 < INT_MIN)
                return INT_MIN;
            else
                ans *= 10;
            if ((long)ans - str[j] + '0' < INT_MIN)
                return INT_MIN;
            ans -= str[j] - '0';
            j++;
        }
    }
    if (j != str.size())
        return 0;
    return ans;
}

int main()
{
    cout << strToInt("11111") << endl;
}