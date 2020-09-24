//给两个有序整数数组，将nums2合并到nums1中，使nums1成为有序数组
#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int l = m - 1;
    int r = n - 1;
    int p = m + n - 1;
    while (l >= 0 && r >= 0)
    {
        nums1[p--] = (nums1[l] < nums2[r]) ? nums2[r--] : nums1[l--];
    }
    if (r >= 0)
    {
        for (r; r >= 0; r--)
            nums1[r] = nums2[r];
    }
}

int main()
{
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    merge(nums1, 3, nums2, 3);
    for (auto c : nums1)
        cout << c << ' ';
}