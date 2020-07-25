#include <iostream>
using namespace std;

int hammingWeight(int x)
{
    int sum = 0;
    while (x != 0)
    {
        sum++;
        x &= (x - 1);
    }
    return sum;
}

int hammingDistance(int x, int y)
{
    int xy = x ^ y;
    return hammingWeight(xy);
}

int main()
{
    int x = 1, y = 4;
    cout << hammingDistance(x, y);
}