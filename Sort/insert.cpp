#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int> &nums, int i, int j)
{
    auto temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void insertSort(vector<int> &nums)
{
    auto len = nums.size();
    for (int i = 1; i < len; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (nums[j - 1] > nums[j])
                swap(nums, j, j - 1);
            else
                break;
        }
    }
}

void insertSort_1(vector<int> &nums)
{
    auto len = nums.size();
    //循环不变量，将nums[i]插入区间[0,i)
    for (int i = 1; i < len; i++)
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