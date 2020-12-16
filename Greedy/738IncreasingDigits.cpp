//给定非负整数N，找出小于或等于N的最大整数，满足各个位数上数字单调递增
#include <vector>
#include <iostream>
using namespace std;

int increasingDigits(int N)
{
    string strN = to_string(N);
    int i = 1;
    while (i < strN.size() && strN[i - 1] <= strN[i]) //从高位到低位
    {
        i++;
    }
    if (i < strN.length())
    {
        while (i > 0 && strN[i - 1] > strN[i]) //高位大于低位
        {
            strN[i - 1]--; //高位-1
            i--;
        }
        for (i += 1; i < strN.size(); i++)//低位置9
            strN[i] = '9';
    }
    return stoi(strN);
}

int incresDigits(int N)
{
    int res = 0;
    int seed = 1;
    while (N > 0)
    {
        int num = N % 10;
        N /= 10;
        int high = N % 10;
        if (high > num)
        {
            //高位大于低位，低位置9,高位-1
            res = seed * 10 - 1;
            N--;
        }
        else
        {
            res = num * seed + res;
        }
        seed *= 10;
    }
    return res;
}