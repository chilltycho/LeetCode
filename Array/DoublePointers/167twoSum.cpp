/*升序数组，找到两数之和，使相加之和等于目标数。index1小于index2*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int l = 0, r = numbers.size()-1;
    while (l < r)
    {
        int sum = numbers[l] + numbers[r];
        if (sum == target)
            return vector<int>{l+1, r+1};
        if (sum < target)
            l++;
        else
            r--;
    }
    return vector<int>{-1,-1};
}

int main()
{
    vector<int> vi1{2, 7, 11, 15};
    auto res1 = twoSum(vi1, 9);
    for (auto c : res1)
        cout << c << ' ';
}