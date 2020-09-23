#include <map>
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) //给定targetsum，找出nums中两数之和为target，答案唯一
{
    for (int i = 0; i < nums.size(); i++)
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] == target - nums[i])
                return vector<int>{i, j};
        }
}

vector<int> twoSum_1(vector<int> &nums, int target)
{
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (m.find(complement) != m.end())
            return vector<int>{m[complement], i};
        m[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> vi{2, 7, 11, 15};
    int target = 9;
    auto re = twoSum_1(vi, target);
    for (auto c : re)
        cout << c << ' ';
}