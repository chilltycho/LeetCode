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

int findBestValue(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end()); // 排序，前几个小于i的，后几个变为i
    int n = arr.size();
    vector<int> prefix(n + 1, 0); // 快速计算改变后总和
    for (int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + arr[i - 1]; 
    int r = *max_element(arr.begin(), arr.end());
    int res = 0, diff = target;
    for (int i = 1; i <= r; ++i) // 左右边界l,r
    {
        auto iter = lower_bound(arr.begin(), arr.end(), i);
        int cur = prefix[iter - arr.begin()] + (arr.end() - iter) * i;
        if (abs(cur - target) < diff)
        {
            res = i;
            diff = abs(cur - target);
        }
    }
    return res;
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