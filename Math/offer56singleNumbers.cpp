//一个整型数组里除了两个数字外，其他数字都出现了两次，找出这两个数字，要求时间O(n),空间O(1)
#include <iostream>
#include <vector>
using namespace std;
/*考虑除了一个数字外，其他数字都出现两次，则用异或。
扩展到两个数字：
1. 两个只出现一次的数字在不同分组
2. 相同数字被分到相同的组中
先全部异或，得到a^b的结果x。再次遍历，若xi=1则分到第二组，否则
分到第一组。xi=1表示ai,bi不等。可知道它们被分到两个组*/
vector<int> singleNumbers(vector<int> &nums)
{
    int ret = 0;
    for (auto &n : nums)
        ret ^= n;//ret为a^b
    int div = 1;
    while ((div & ret) == 0)
        div <<= 1;//只要找到其中一位等于1的
    int a = 0, b = 0;//结果
    for (auto &n : nums)
        if (div & n)
            a ^= n;
        else
            b ^= n;
    return vector<int>{a, b};
}