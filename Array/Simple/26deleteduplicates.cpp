#include <iostream>
using namespace std;
//删除数组中重复元素，返回删除后数组大小，无需考虑新长度后面元素。
int deletedup(int *a, int n)
{
    int p = 0, q = 1;
    for (; q < n; q++)
    {
        if (a[p] != a[q])
        {
            p++;
            if (p != q)
                a[p] = a[q];
        }
    }
    return p + 1;
}

int main()
{
    int a[]{0, 0,1, 2, 3, 3, 4};
    int re = deletedup(a, sizeof(a) / sizeof(int));
    for (int i = 0; i < re; i++)
        cout << a[i] << ' ';
}