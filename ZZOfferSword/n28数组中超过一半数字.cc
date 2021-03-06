// 求数组中超过一半数字，若没有，返回0
#include <vector>
#include <iostream>
using namespace std;

int moreThanHalfNum(vector<int> &numbers)
{
    int res = -1;
    int cnt = 0;
    for (auto c : numbers)
    {
        if (cnt == 0)
        {
            ++cnt;
            res = c;
        }
        else
        {
            if (c == res)
                ++cnt;
            else
                --cnt;
        }
    }
    cnt = 0;
    for (auto k : numbers)
        if (res == k)
            ++cnt;
    if (cnt * 2 <= numbers.size())
        return 0;
    return res;
}