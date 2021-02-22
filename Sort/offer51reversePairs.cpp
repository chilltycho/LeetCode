//在数组中两个数字，若前面大于后面，则组成逆序对，求数组中逆序对总数
#include <vector>
#include <iostream>
using namespace std;

// 暴力法
int reversePairs_vio(vector<int> &nums)
{
    int res = 0;
    int len = nums.size();
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
            if (nums[i] > nums[j])
                res++;
    }
    return res;
}

/**借助归并排序统计逆序数
 * 合并两个有序数组，利用数组的部分有序性。
 * 前面【分】的时候什么都不做，【合】的过程计算【逆序对】个数。
 * 所有【逆序对】来于三部分：1.左边区间逆序对 2.右边区间逆序对 3.横跨两区间逆序对
*/
int mergeAndCount(vector<int> &nums, int left, int mid, int right)
{
    int len = right - left + 1;
    vector<int> temp(len);
    for (int i = 0; i < len; i++)
        temp[i] = nums[left + i];
    int l = left;
    int r = mid + 1;
    int count = 0;
    for (int k = left; k <= right; k++)
    {
        if (l == mid + 1) //左边耗尽
        {
            nums[k] = temp[r];
            r++;
        }
        else if (r == right + 1) //右边耗尽
        {
            nums[k] = temp[l];
            l++;
        }
        else if (temp[l] <= temp[r])
        {
            nums[k] = temp[l];
            l++;
        }
        else //前面大于后面，计算逆序对
        {
            nums[k] = temp[r];
            r++;
            count += (mid - l + 1);
        }
    }
    return count;
}

int reversePairs_help(vector<int> &nums, int left, int right)
{
    if (left == right)
        return 0;
    int mid = left + (right - left) / 2;
    int leftPairs = reversePairs_help(nums, left, mid);
    int rightPairs = reversePairs_help(nums, mid + 1, right);
    if (nums[mid] <= nums[mid + 1]) //数组已经有序
        return leftPairs + rightPairs;
    int crossPairs = mergeAndCount(nums, left, mid, right);
    return leftPairs + rightPairs + crossPairs;
}

int reversePairs(vector<int> &nums)
{
    auto len = nums.size();
    if (len < 2)
        return 0;
    return reversePairs_help(nums, 0, len - 1);
}

int main()
{
    vector<int> nums{7, 5, 6, 4};
    cout << reversePairs(nums);
}