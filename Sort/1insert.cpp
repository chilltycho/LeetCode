#include <iostream>
#include <vector>
using namespace std;
/*
稳定排序，最好O(n)，最坏O(n^2)
*/
void insertSort(vector<int> &nums)
{
    auto len = nums.size();
    // 共需n-1次
    for (size_t i = 1; i < len; i++)
    {
        // 新牌为nums[j]
        for (size_t j = i; j > 0; j--)
        {
            if (nums[j - 1] > nums[j])
                swap(nums[j], nums[j - 1]);
            else
                break;
        }
    }
}

// 对排好序的为O(N)
void insertSort_1(vector<int> &nums)
{
    auto len = nums.size();
    //循环不变量，将nums[i]插入区间[0,i)
    for (size_t i = 1; i < len; i++)
    {
        int temp = nums[i];
        int j = i;
        while (j > 0 && nums[j - 1] > temp)
        {
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = temp;
    }
}

int main()
{
    vector<int> nums{4, 7, 2, 3, 5, 1, 8, 6};
    insertSort(nums);
    for (auto c : nums)
        cout << c << ' ';
}