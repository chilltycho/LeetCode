#include <vector>
using namespace std;
int first(vector<int> &data, int k)
{
    int l = 0, r = data.size();
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (data[m] < k)
            l = m + 1;
        else
            r = m;
    }
    return l; // 最左索引
}

int last(vector<int> &data, int k)
{
    int l = 0, r = data.size();
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (data[m] <= k)
            l = m + 1;
        else
            r = m;
    }
    return l; // 最后一个元素索引+1
}