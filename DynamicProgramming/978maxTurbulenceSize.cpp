/*湍流子数组：比较符号在子数组中每个相邻元素对之间翻转
输入：[9,4,2,10,7,8,8,1,9] 输出：5 (A[1]>A[2]<A[3]>A[4]<A[5])*/
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

//定义两个子问题：1.最后一段上升f(k) 2.最后一段下降g(k)
int maxTurbulenceSize(vector<int> &A)
{
        auto arr = A;
        int sz = arr.size();
        vector<int> l(sz, 1), r(sz, 1);// l为>, r为<
        int res = 1;
        for (int i = 1; i < sz; ++i)
        {
            if (arr[i] > arr[i - 1])
                r[i] = l[i - 1] + 1;
            else if (arr[i] < arr[i - 1])
                l[i] = r[i - 1] + 1;
            res = max(res, max(l[i], r[i]));
        }
        return res;
}

int main()
{
    vector<int> A{9, 4, 2, 10, 7, 8, 8, 1, 9};
    assert(5 == maxTurbulenceSize(A));
    vector<int> B{4, 8, 12, 16};
    assert(2 == maxTurbulenceSize(B));
    vector<int> C{1};
    assert(1 == maxTurbulenceSize(C));
}