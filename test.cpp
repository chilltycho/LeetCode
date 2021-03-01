#include <climits>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void mergeC(vector<int> &x, int l, int m, int r)
{
    int len = r - l + 1;
    vector<int> temp(len);
    for (int i = 0; i < len; i++)
        temp[i] = x[i + l];
    int lt = 0;
    int rt = m - l + 1;
    for (int i = 0; i < len; i++)
    {
        if (lt + l > m)
            x[i + l] = temp[rt++];
        else if (rt > len - 1)
            x[i + l] = temp[lt++];
        else if (temp[lt] > temp[rt])
            x[i + l] = temp[lt++];
        else
            x[i + l] = temp[rt++];
    }
}

void merge(vector<int> &x, int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    merge(x, l, m);
    merge(x, m + 1, r);
    mergeC(x, l, m, r);
}

int main()
{
    
}