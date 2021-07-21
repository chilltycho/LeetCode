#include <string>
#include <algorithm>
using namespace std;
string LeftRotateString(string str, int n)
{
    int len = str.size();
    if (len < 2)
        return str;
    n %= len;
    auto s1 = str.substr(0, n);
    auto s2 = str.substr(n, len - n);
    return s2 + s1;
    //     reverse(s1.begin(), s1.end());
    //     reverse(s2.begin(), s2.end());
    //     auto tmp = s1 + s2;
    //     reverse(tmp.begin(), tmp.end());
    //     return tmp;
}