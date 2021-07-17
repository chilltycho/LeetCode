//给定整数数组，寻找连续子数组，若对这个子数组升序排序，则整个数组变为升序排序
#include <vector>
#include <cassert>
#include <stack>
using namespace std;
//向左找最远递增的序号，向右找最远递减
int findUnsortedSubarray(vector<int> &nums)
{
    int l = nums.size(), r = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[i])
            {
                r = max(r, j);
                l = min(l, i);
            }
        }
    }
    return r - l < 0 ? 0 : r - l + 1;
}
// 左段（升序），中段（乱序），右段（升序）
int findUnsortedSubarray_1(vector<int> &nums)
{
    if (nums.empty() || nums.size() == 1)
        return 0;
    int begin = 0, end = -1; // 中段的左右边界
    int len = nums.size();
    int min = nums[len - 1]; //从右到左
    int max = nums[0];       //从左到右
    for (int i = 0; i < len; i++)
    {
        if (nums[i] < max) // 左段升序结束
            end = i;
        else
            max = nums[i];
        if (nums[len - i - 1] > min)// 右端降序结束
            begin = len - i - 1;
        else
            min = nums[len - i - 1];
    }
    return end - begin + 1;
}

int main()
{
    vector<int> vi{2, 6, 4, 8, 10, 9, 15};
    assert(5 == findUnsortedSubarray_1(vi));
}