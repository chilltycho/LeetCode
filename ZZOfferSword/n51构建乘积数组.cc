/**
 * 给定数组A，构建B的元素为对应A除当前元素，其他元素积
*/
#include <vector>
#include <iostream>
using namespace std;

vector<int> construct(vector<int> &a)
{
    int n = a.size();
    vector<int> left(n, 1);  //i左侧乘积
    vector<int> right(n, 1); //i右侧乘积
    for (int i = 1; i < n; i++)
        left[i] = left[i - 1] * a[i - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = right[i - 1] * a[i - 1];
    vector<int> res;
    for (int i = 0; i < n; i++)
        res.push_back(left[i] * right[i]);
    return res;
}

vector<int> constructArr(vector<int> &a)
{
    int len = a.size();
    vector<int> b(len, 1);
    int l = 1, r = 1;
    for (int i = 0; i < len; i++)
    {
        b[i] *= l;
        l *= a[i];

        b[len - i - 1] *= r;
        r *= a[len - i - 1];
    }
    return b;
}