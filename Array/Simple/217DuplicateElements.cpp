#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            return true;
        }
    }
    return false;
}

bool containsDuplicate_1(vector<int>& nums)
{
    set<int> mi;
    for(auto const &c:nums)
    {
        if(mi.count(c))
            return true;
        mi.insert(c);
    }
    return false;
}

int main()
{
    vector<int> a{3, 2, 1, 4, 5, 6, 0};
    vector<int> b{3, 2, -1, 4, 5, 6, 0, -1};
    cout << containsDuplicate(a) << endl;
    cout << containsDuplicate(b) << endl;
}