/*给定两大小为m和n的升序数组nums1和nums2,找出中位数*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/**
 * len为合并后数组长度，若为奇数，需知道第(len+1)/2个数，需遍历int(len/2)+1次。
 * 若为偶数，需知道第len/2和len/2+1个数，需遍历len/2+1次。
 * 所以都需遍历len/2+1次。用left保存上次循环值，right保存当前循环值
*/
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    int len = m + n;
    int ap = 0, bp = 0;
    int left = -1, right = -1;
    for (int i = 0; i <= len / 2; i++)
    {
        left = right;
        if (ap < m && (bp >= n || nums1[ap] < nums2[bp]))
        {
            right = nums1[ap++];
        }
        else
            right = nums2[bp++];
    }
    if ((len & 1) == 0)
        return (left + right) / 2.0;
    else
        return right;
}

int getKth(vector<int> &nums1, int start1, int end1, vector<int> &nums2, int start2, int end2,
           int k)
{
    int len1 = end1 - start1 + 1;
    int len2 = end2 - start2 + 1;
    //确保len1长度小于len2,保证若数组空了,一定为len1
    if (len1 > len2)
        return getKth(nums2, start2, end2, nums1, start1, end1, k);
    if (len1 == 0)
        return nums2[start2 + k - 1];
    if (k == 1)
        return min(nums1[start1], nums2[start2]);
    int i = start1 + min(len1, k / 2) - 1;
    int j = start2 + min(len2, k / 2) - 1;
    if (nums1[i] > nums2[j]) //排除nums2一部分
    {
        return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
    }
    else
    {
        return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
    }
}

//找第k小的数
//两个数组选出k/2个数,排除小的那部分
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int left = (n + m + 1) / 2;
    int right = (n + m + 2) / 2;
    //将偶数和奇数情况合并,若为奇数,求两次同样的k
    return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) +
            getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) *
           0.5;
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