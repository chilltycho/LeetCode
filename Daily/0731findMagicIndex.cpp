#include <iostream>
#include <vector>
using namespace std;

//升序数组A[0..n-1]，若A[i]=i则为魔术数组。有的话，找到最小的。没有返回-1

int findMagicIndex_1(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == i)
            return i;
    }
    return -1;
}

int findMagicIndex_2(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == i)
            return i;
        if (nums[i] > i)
            i = nums[i] - 1;
    }
    return -1;
}

int bisearch(vector<int> &nums, int lo, int hi)//直接二分法找到的i不一定最小
{
    if (lo > hi)
        return -1;
    int mid = lo + (hi - lo) / 2;
    int res = bisearch(nums, lo, mid - 1);
    if (res != -1)
        return res;
    else if (nums[mid] == mid)
        return mid;
    else
        return bisearch(nums, mid + 1, hi);
}

int findMagicIndex_3(vector<int> &nums)
{
    return bisearch(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums{1, 1, 1};
    cout << findMagicIndex_1(nums);
}