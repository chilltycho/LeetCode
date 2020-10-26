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

int longestMountain_1(vector<int> &A)
{
    int len = A.size();
    if (len < 3)
        return 0;
    //left[i]表示向左能扩展元素个数
    vector<int> left(len, 0), right(len, 0);
    for (int i = 1; i < len; i++)
    {
        if (A[i - 1] < A[i])
            left[i] = left[i - 1] + 1;
    }
    for (int i = len - 2; i >= 0; i--)
    {
        if (A[i + 1] < A[i])
            right[i] = right[i + 1] + 1;
    }
    int res = 0;
    for (int i = 0; i < len; i++)
        res = max(res, left[i] + right[i] + 1);
    return res;
}

int main()
{
    vector<int> vi{0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
    vector<int> vi1{2, 1, 4, 7, 3, 2, 5};
    cout << longestMountain(vi1) << endl;
}