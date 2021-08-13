// 求两个已经排序区间的交集
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
{
    int l = 0, r = 0;
    vector<vector<int>> res;
    while (l < firstList.size() && r < secondList.size())
    {
        int a = firstList[l][0], b = firstList[l][1];
        int x = secondList[r][0], y = secondList[r][1];
        if (a > y)
            ++r;
        else if (b < x)
            ++l;
        else // 相交时
        {
            int maxl = max(a, x);
            int minr = min(b, y);
            res.push_back(vector<int>{maxl, minr});
            if (minr == b)
                ++l;
            else
                ++r;
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> a{{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    vector<vector<int>> b{{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    for (auto c : intervalIntersection(a, b))
        cout << c[0] << ' ' << c[1] << ' ';
    // [[ 1, 2 ], [ 5, 5 ], [ 8, 10 ], [ 15, 23 ], [ 24, 24 ], [ 25, 25 ]]
}