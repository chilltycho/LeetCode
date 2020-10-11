//给定未排序整数数组，找出未出现的最小正整数
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int len = nums.size();
    set<int> hashSet;
    for (int num : nums)
        hashSet.insert(num);
    for (int i = 1; i <= len; i++)
        if (hashSet.find(i) == hashSet.end())
            return i;
    return len + 1;
}

int firstMissingPositive_hash(vector<int> &nums)
{
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        //数值3应放在索引2上
        while (nums[i] > 0 && nums[i] <= len && 
                    nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);
    }
    for (int i = 0; i < len; i++)
        if (nums[i] != i + 1)
            return i + 1;
    return len + 1;
}

int main()
{
    vector<int> vi{1, 2, 0};
    cout << firstMissingPositive_hash(vi);
    vector<int> vi1{4,3,2,7,8,3,2,1};
    cout<<firstMissingPositive_hash(vi1);
}