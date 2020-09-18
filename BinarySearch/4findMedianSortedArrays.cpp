/*给定两大小为m和n的升序数组nums1和nums2,找出两个中位数*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    int medianIndex = (m + n) / 2;//

    int counter = -1;
    int i = 0;
    int j = 0;

    int res[2]{0, 0};
    while (counter < medianIndex)
    {
        counter++;
        if (i == m) //数组1耗尽
        {
            res[counter & 1] = nums2[j];
            j++;
        }
        else if (j == n)
        {
            res[counter & 1] = nums1[i];
            i++;
        }
        else if (nums1[i] < nums2[j])
        {
            res[counter & 1] = nums1[i];
            i++;
        }
        else
        {
            res[counter & 1] = nums2[j];
            j++;
        }
    }
    if (((n + m) & 1) == 1)
        return res[counter & 1];
    else
        return (double)(res[0] + res[1]) / 2;
}

int main()
{
    vector<int> nums1{1, 3};
    vector<int> nums2{2}; //中位数为2.0
    assert(2.0 == findMedianSortedArrays(nums1, nums2));
    vector<int> nums3{1, 2};
    vector<int> nums4{3, 4};
    assert(2.5 == findMedianSortedArrays(nums3, nums4)); //(2+3)/2=2.5
}