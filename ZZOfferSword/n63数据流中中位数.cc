#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> vi;
void Insert(int num)
{
    vi.push_back(num);
}

double GetMedian()
{
    sort(vi.begin(), vi.end());
    int sz = vi.size();
    {
        if (sz & 1)
            return vi[sz >> 1] * 1.0;
        else
            return (vi[sz >> 1] * 1.0 + vi[(sz - 1) >> 1] * 1.0) / 2;
    }
}