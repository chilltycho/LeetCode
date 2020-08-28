/*湍流子数组：比较符号在子数组中额每个相邻元素对之间翻转
输入：[9,4,2,10,7,8,8,1,9] 输出：5 (A[1]>A[2]<A[3]>A[4]<A[5])*/
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

//定义两个自问题：1.最后一段上升f(k) 2.最后一段下降g(k)
int maxTurbulenceSize(vector<int> &A)
{
    if (A.empty())
        return 0;
    const auto size = A.size();
    int f[size + 1], g[size + 1];
    f[0] = 0;
    g[0] = 0;
    f[1] = 1;
    g[1] = 1;
    int res = 1;
    for (int i = 2; i <= size; i++)
    {
        if (A[i - 1] > A[i - 2]) //最后一段上升
        {
            f[i] = g[i - 1] + 1;
            g[i] = 1;
        }
        else if (A[i - 1] < A[i - 2]) //最后一段下降
        {
            g[i] = f[i - 1] + 1;
            f[i] = 1;
        }
        else
        {
            f[i] = 1;
            g[i] = 1;
        }
        res = max(max(res, f[i]), g[i]);
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