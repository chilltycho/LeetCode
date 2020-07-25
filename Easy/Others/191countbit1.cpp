#include <iostream>
using namespace std;

int hammingWeight(uint32_t n)
{
    uint32_t bits = 0;
    uint32_t mask = 1;
    for (int i = 0; i < 32; i++)
    {
        if ((mask & n) != 0)
            bits++;
        mask <<= 1;
    }
    return bits;
}

int hammingWeight_1(uint32_t n)//对任意数字n，将n和n-1做与运算，会把n最低位的1变成0
{
    uint32_t sum = 0;
    while (n != 0)
    {
        sum++;
        n &= (n - 1);
    }
    return sum;
}

int main()
{
    cout << hammingWeight_1(0x1011);
}