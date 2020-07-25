#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge_1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = n, j = 0; i < m+n; i++)
        nums1[i] = nums2[j++];
    sort(nums1.begin(), nums1.end());
}

void merge_2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> nums;
    int p1 = 0, p2 = 0;
    while ((p1 < m) && (p2 < n))
        nums.push_back(nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++]);
    if (p1 < m)
        for (int i = p1; i < m; i++)
            nums.push_back(nums1[i]);
    if (p2 < n)
        for (int i = p2; i < n; i++)
            nums.push_back(nums2[i]);
    nums1 = nums;
}

void merge_3(vector<int> &nums1,int m,vector<int> &nums2,int n)
{
    int p1=m-1;
    int p2=n-1;
    int p=m+n-1;

    while((p1>=0)&&(p2>=0))
        nums1[p--]=nums1[p1]<nums2[p2]?nums2[p2--]:nums1[p1--];
    for(int i=0;i<p2+1;i++)
        nums1[i]=nums2[i];
}

int main()
{
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    merge_3(nums1, 3, nums2, 3);
    for (auto c : nums1)
        cout << c << ' ';
}