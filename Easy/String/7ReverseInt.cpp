#include <iostream>
using namespace std;
//若反转后溢出，输出0
int reverse(int x)
{
    int rev = 0;
    while (x != 0)
    {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
            return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
            return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}

int main()
{
    cout << "INT_MAX " << INT_MAX << endl;
    cout << "INT_MIN " << INT_MIN << endl;

    int re = reverse(INT_MAX);
    cout << re << endl;
}