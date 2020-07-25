#include <iostream>
#include <vector>
using namespace std;

//0到n间缺少一个数字

int missingNumber(vector<int> &nums) //missing=4^(0^0)^(1^1)^(3^4)
{
    int missing = nums.size();
    for (int i = 0; i < nums.size(); i++)
        missing ^= i ^ nums[i];
    return missing;
}

int missingNumber_1(vector<int> &nums)
{
    int expectedSum = nums.size() * (nums.size() - 1) / 2;
    int actualSum = 0;
    for (auto n : nums)
        actualSum += n;
    return expectedSum - actualSum;
}