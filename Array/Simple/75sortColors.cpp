//给定0,1,2的n维数组，原地进行排序
#include <vector>
#include <iostream>
using namespace std;

//计数排序，先统计0，1，2个数，再排序
void sortColors(vector<int> &nums)
{
    int numsZero = 0;
    int numsOnes = 0;
    int numsTwos = 0;
    for (const auto &c : nums)
    {
        if (c == 0)
            numsZero++;
        else if (c == 1)
            numsOnes++;
        else
            numsTwos++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (i < numsZero)
            nums[i] = 0;
        else if (i < numsOnes + numsZero)
            nums[i] = 1;
        else
            nums[i] = 2;
    }
}
//用p0 p2 cur分别追踪0的最右边界，2的最左边界和当前考虑的元素
void sortColors_1(vector<int> &nums)
{
    int p0 = -1;//维护0集合
    int cur = 0;
    int p2 = nums.size();//维护2集合
    while (cur < p2)
    {
        if (nums[cur] == 0)
        {
            swap(nums[++p0], nums[cur++]);
        }
        else if (nums[cur] == 2)//2时不能cur++,nums[--p2]可能为0
        {
            swap(nums[--p2], nums[cur]);
        }
        else
            cur++;
    }
}

int main()
{
    vector<int> vi{1, 2, 0};
    sortColors_1(vi);
    for (auto c : vi)
        cout << c << ' ';
}