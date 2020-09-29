#include <vector>
#include <iostream>
using namespace std;
//数组元素表示各位的值，如[1,2,3]表示123。要求输出[1,2,4]
vector<int> plusOne(vector<int> &digits)
{
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        digits[i]++;
        digits[i] = digits[i] % 10;
        if (digits[i] != 0)//无进位，否则继续高位+1
            return digits;
    }
    //需扩容
    digits = vector<int>(digits.size() + 1);
    digits[0] = 1;
    return digits;
}

int main()
{
    vector<int> vi{9,9};
    auto re = plusOne(vi);
    for (auto c : re)
        cout << c << ' ';
}