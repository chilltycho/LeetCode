// 和为s连续正数序列
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> findContinuousSequence(int target)
{
    int len = target / 2 + 1;
    vector<vector<int>> res;
    int sum = 0;
    for (int l = 1, r = 1; r <= len; ++r)
    {
        sum += r;
        while (sum > target)
        {
            sum -= l;
            ++l;
        }
        if (sum == target)
        {
            vector<int> tmp;
            for (int i = l; i <= r; ++i)
                tmp.push_back(i);
            res.push_back(tmp);
            sum -= l;
            ++l;
        }
    }
    return res;
}

int main()
{
    auto res = findContinuousSequence(9);
}