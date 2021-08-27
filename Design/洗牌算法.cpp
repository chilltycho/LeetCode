/*
1. 随机的结果能够覆盖所有情况，如n个数，最后结果n!情况
2. 所有出现的结果概率相等
*/
#include <vector>
#include <random>
#include <iostream>
using namespace std;
size_t getrand(int l, int r)
{
    return rand() % (r - l) + l;
}
void shuffle(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        int rand1 = getrand(i, n);
        swap(nums[rand1], nums[i]);
    }
}

int main()
{
    vector<int> nums{1, 2, 3, 4};
    shuffle(nums);
    for (auto c : nums)
        cout << c << ' ';
}