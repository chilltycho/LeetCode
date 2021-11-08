/*给定正整数数组arr,和target。确定一个整数，使将数组中所有大于value的值变为value后，
数组和最接近target。若有多种方案，返回value最小值
1<=arr.length<=10^4
1<=arr[i],target<=10^5*/
#include <vector>
#include <cmath>
#include <climits>
#include <cassert>
#include <algorithm>
using namespace std;

int cal(vector<int> &arr, int val)
{
    int res = 0;
    for (auto c : arr)
        res += min(c, val);
    return res;
}

int findBestValue(vector<int> &arr, int target)
{
    int l = 0, r = *max_element(arr.begin(), arr.end());
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (cal(arr, m) < target)
            l = m + 1;
        else
            r = m;
    }
    if (abs(cal(arr, l - 1) - target) <= abs(cal(arr, l) - target))
        return l - 1;
    return l;
}

int main()
{
    vector<int> vi{4, 9, 3};
    assert(3 == findBestValue(vi, 10));
    vector<int> vi1{2, 3, 5};
    assert(5 == findBestValue(vi1, 10));
    vector<int> vi2{60864, 25176, 27249, 21296, 20204};
    assert(11361 == findBestValue(vi2, 56803));
}