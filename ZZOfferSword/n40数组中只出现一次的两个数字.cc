#include <vector>
using namespace std;
vector<int> FindNumsAppearOnce(vector<int> &array)
{
    vector<int> res{-1,-1};
    int x = array[0];
    for (int i = 1; i < array.size(); ++i)
        x ^= array[i]; // 单独出现数字的异或结果
    int m = 1;
    while ((m & x) == 0) // 两个单独出现的数字在m位相异，则在x中第m位为1
        m <<= 1;
    for (auto i : array)
    {
        if ((m & i) == 0)
            res[0] ^= i;
        else
            res[1] ^= i;
    }
    if (res[0] > res[1])
        swap(res[0], res[1]);
    return res;
}