/*
把数组A中符合下列属性的任意连续子数组B称为“山脉”：
B.length >= 3
存在0 < i < B.length -1使得B[0] < B[1] < ... < B[i-1] < B[i]
> B[i+1] > ... > B[B.length - 1]
返回A中最长“山脉”的长度。
*/
#include <vector>
#include <iostream>
using namespace std;

int longestMountain(vector<int> &A)
{
    if (A.size() < 3)
        return 0;
    size_t res = 0;
    size_t l = 0;
    size_t r = 0;
    for (size_t i = 1; i < A.size() - 1; i++)
    {
        l = i;
        r = i;
        while (l >= 1 && A[l - 1] < A[l])
        {
            l--;
        }
        while (r < A.size() - 1 && A[r + 1] < A[r])
        {
            r++;
        }
        if (l == r || l == i || r == i)
            continue;
        res = max(res, r - l + 1);
    }

    return res;
}

int longestMountain_1(vector<int> &arr)
{
    int len = arr.size();
    if (len < 3)
        return 0;
    vector<int> l(len, 0), r(len, 0);
    for (int i = 1; i < len; i++)
        if (arr[i - 1] < arr[i])
            l[i] = l[i - 1] + 1;
    for (int i = len - 2; i >= 0; i--)
        if (arr[i] > arr[i + 1])
            r[i] = r[i + 1] + 1;
    int res = 0;
    for (int i = 0; i < len; i++)
        if (l[i] != 0 && r[i] != 0)
            res = max(l[i] + r[i] + 1, res);
    return res;
}

int main()
{
    vector<int> vi{0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
    vector<int> vi1{2, 1, 1, 5, 6, 2, 3, 1};
    cout << longestMountain(vi1) << endl;
}