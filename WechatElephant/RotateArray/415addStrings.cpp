#include <iostream>
#include <algorithm>
using namespace std;
//给定两个字符串形式的非负整数num1,num2计算它们的和。不包含前导0，只包含0-9

string addStrings(string num1, string num2)
{
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res;
    int n1, n2, temp;
    while (i >= 0 || j >= 0)
    {
        if (i >= 0)
            n1 = num1[i] - '0';
        else
            n1 = 0;
        if (j >= 0)
            n2 = num2[j] - '0';
        else
            n2 = 0;
        temp = n1 + n2 + carry;
        carry = temp / 10;
        res = to_string(temp % 10) + res;
        i--;
        j--;
    }
    if (carry == 1)
        res = "1" + res;
    return res;
}

string addStrings_1(string num1, string num2)
{
    int n = num1.size(), m = num2.size(), sum = 0;
    n < m ? num1.insert(0, m - n, '0') : num2.insert(0, n - m, '0'); //在头部补0
    for (int i = num1.size() - 1; i >= 0; i--)
    {
        sum = (num1[i] - '0') + (num2[i] - '0') + sum / 10;
        num1[i] = char(sum % 10+'0');
    }
    if (sum / 10 == 1)
        num1 = "1" + num1;
    return num1;
}

int main()
{
    string s1{"51189"};
    string s2{"967895"};
    cout << addStrings_1(s1, s2);
}