#include <iostream>
#include <vector>
using namespace std;
//将已排好序的数组合并，nums[lef,...mid]和nums[mid+1,right]
void merge(vector<int> &nums, int L, int mid, int R)
{
    vector<int> rec;
    int i = L, j = mid + 1;
    while (i <= mid && j <= R)
    {
        if (nums[i] <= nums[j])
            rec.push_back(nums[i++]);
        else
            rec.push_back(nums[j++]);
    }
    while (i <= mid)
        rec.push_back(nums[i++]);
    while (j <= R)
        rec.push_back(nums[j++]);
    for (int i = 0; i < rec.size(); i++)
        nums[L + i] = rec[i];
}

void mergesort(vector<int> &nums, int L, int R)
{
    if (L >= R)
        return;
    int mid = (L + R) >> 1;
    mergesort(nums, L, mid);
    mergesort(nums, mid + 1, R);
    merge(nums, L, mid, R);
}

int main()
{
    vector<int> vi{8, 7, 6, 5, 4, 3, 2, 1};
    mergesort(vi, 0, vi.size() - 1);
    for (auto c : vi)
        cout << c << ' ';
}
