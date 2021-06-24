#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int m_lowerbound(vector<int> &nums, int target)
{
    size_t l = 0, r = nums.size();
    while (l < r)
    {
        auto m = l + (r - l) / 2;
        if (nums[m] < target)
            l = m + 1;
        else
            r = m;
    }
    return l; // l和r一样
}

int m_upperbound(vector<int> &nums, int target)
{
    size_t l = 0, r = nums.size();
    while (l < r)
    {
        auto m = l + (r - l) / 2;
        if (nums[m] <= target)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int main()
{
    vector<int> vs{0, 1, 2, 3, 3, 5, 6};
    cout << lower_bound(vs.begin(), vs.end(), 3) - vs.begin() << endl;
    cout << upper_bound(vs.begin(), vs.end(), 3) - vs.begin() << endl;
}