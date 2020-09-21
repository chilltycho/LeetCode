/*给定非负整数数组和整数m，将数组分成m个非空的连续子数组，设计算法使m个子数组各自和的最大值最小*/
#include <vector>
#include <cassert>
using namespace std;

int split(vector<int> &nums, int maxIntervalSum)
{
    int splits = 1; //即使不分，也有一组
    int curIntervalSum = 0;
    for (int num : nums)
    {
        if (curIntervalSum + num > maxIntervalSum) //分一组
        {
            curIntervalSum = 0;
            splits++;
        }
        curIntervalSum += num;
    }
    return splits;
}
int splitArray(vector<int> &nums, int m)
{
    if (m > nums.size())
        return -1;
    int biggest = 0;
    int sum = 0;
    for (int num : nums)
    {
        biggest = max(biggest, num);
        sum += num;
    }
    int left = biggest; //maxIntervalSum的最小值，每个数为一组
    int right = sum;    //maxIntervalSUm最大值，整个数组为一组
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int splits = split(nums, mid);
        if (splits > m) //分组超过要求，增加maxIntervalSum左区间
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main()
{
    vector<int> nums{7, 2, 5, 10, 8};
    assert(18 == splitArray(nums, 2)); //分为[7,2,5]和[10,8]
}