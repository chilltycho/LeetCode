//给定范围在1<=a[i]<=n的整型数组，找到所有在[1,n]范围内未出现在数组中数组
#include <vector>
#include <iostream>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int newIndex = abs(nums[i]) - 1;
        if (nums[newIndex] > 0)
            nums[newIndex] *= -1;
    }
    vector<int> res;
    for (int i = 1; i <= nums.size(); i++)
        if (nums[i - 1] > 0)
            res.push_back(i);
    return res;
}

vector<int> findDisappearedNumbers_hash(vector<int> &nums)
{
    for (size_t i = 0; i < nums.size(); i++)
    {
        while (nums[i] > 0 && nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    vector<int> res;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i + 1)
            res.push_back(i + 1);
    }
    return res;
}

int main()
{
    vector<int> vi{1, 1};
    auto res = findDisappearedNumbers_hash(vi);
    for (auto c : res)
        cout << c << ' ';
}