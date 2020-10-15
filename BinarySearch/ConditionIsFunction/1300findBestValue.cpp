/*给定正整数数组arr,和target。确定一个整数，使将数组中所有大于value的值变为value后，
数组和最接近target。若有多种方案，返回value最小值
1<=arr.length<=10^4
1<=arr[i],target<=10^5*/
#include <vector>
#include <cmath>
#include <climits>
#include <cassert>
using namespace std;
int calDis(vector<int> &arr, int value)
{
    int dis = 0;
    for (auto c : arr)
    {
        if (c > value)
            dis += value;
        else
            dis += c;
    }
    return dis;
}

int findBestValue(vector<int> &arr, int target)
{
    int left = 1;
    int maxval = 0;
    for (auto c : arr)
        maxval = max(maxval, c);
    int right = maxval;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (calDis(arr, mid) < target)
            left = mid + 1;
        else
            right = mid;
    }
    int dis1 = calDis(arr, left - 1);
    int dis2 = calDis(arr, left);
    if (abs(target - dis1) <= abs(target - dis2))
        return left - 1;
    return left;
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