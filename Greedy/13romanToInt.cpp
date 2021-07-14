#include <iostream>
#include <cassert>
#include <unordered_map>
using namespace std;

//当小值在大值左边,减小值 IV=5-1=4,同时观察两位
int romanToInt(string s)
{
    unordered_map<char, int> um{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int res = 0;
    int pre = um[s[0]];
    for (int i = 1; i < s.size(); i++)
    {
        int cur = um[s[i]];
        if (pre < cur)
            res -= pre;
        else
            res += pre;
        pre = cur;
    }
    return res + pre;
}

int main()
{
    assert(3 == romanToInt("III"));
    assert(4 == romanToInt("IV"));
    assert(9 == romanToInt("IX"));
    assert(58 == romanToInt("LVIII"));
}