/*h指数指n篇论文中总共有h篇论文分别被引用了至少h次，其余的n-h少于h次
输入[0,1,3,5,6] 输出3*/
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

int hIndex(vector<int> &citations) //暴力法，升序排列
{
    int len = citations.size();
    for (int i = 0; i < len; i++)
    {
        if (citations[i] >= (len - i))
            return len - i;
    }
    return 0;
}

int hIndex_bi(vector<int> &citations)
{
    int len = citations.size();
    if (len == 0)
        return 0;
    int left = 0;
    int right = len - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (citations[mid] == (len - mid))
            return len - mid;
        if (citations[mid] < (len - mid))
            left = mid + 1;
        else if (citations[mid] > (len - mid))
            right = mid;
    }
    if (citations[left] >= (len - left))
        return len - left;
    else
        return 0;
}

int main()
{
    vector<int> vi{0, 1, 3, 5, 6};
    assert(3 == hIndex_bi(vi));
}