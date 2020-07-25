#include <iostream>
#include <vector>
using namespace std;

void swap(int a[], int l, int r)
{
    int temp = a[l];
    a[l] = a[r];
    a[r] = temp;
}

void quicksort1(int *a, int lo, int hi)
{
    if (hi <= lo)
        return;
    int p = lo, q = hi + 1, i = lo, j = hi + 1;
    int v = a[lo];
    while (true)
    {
        while (a[++i] < v)
            if (i == hi)
                break;
        while (v < a[--j])
            if (j == lo)
                break;
        if (i == j && a[i] == v)
            swap(a, ++p, i);
        if (i >= j)
            break;
        swap(a, i, j);
        if (a[i] == v)
            swap(a, ++p, i);
        if (a[j] == v)
            swap(a, --q, j);
    }
    i = j + 1;
    for (int k = lo; k <= p; k++)
        swap(a, k, j--);
    for (int k = hi; k >= q; k--)
        swap(a, k, i++);
    quicksort1(a, lo, j);
    quicksort1(a, i, hi);
}

bool containsDuplicate(int *nums, int numSize)
{
    quicksort1(nums, 0, numSize - 1);
    for (int i = 1; i < numSize; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            return true;
        }
    }
    return false;
}
#if 1 //考虑负数，考虑nums中数比nums.size()大
bool containsDuplicate(vector<int> &nums)
{
    bool posa[nums.size()]{false};
    bool nega[nums.size()]{false};
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= 0)
        {
            if (posa[nums[i]] == true)
                return true;
            else
                posa[nums[i]] = true;
        }
        else
        {
            int temp=-1*nums[i];
            if(nega[temp]==true)
                return true;
            else
                nega[temp]=true;
        }
    }
    return false;
}
#endif
int main()
{
    int a[]{3, 2, 1, 4, 5, 6, 0};
    vector<int> b{3, 2, -1, 4, 5, 6, 0,-1};
    cout << containsDuplicate(a, 7) << endl;
    cout << containsDuplicate(b) << endl;
}