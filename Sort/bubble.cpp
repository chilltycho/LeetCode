#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int> &nums, int i, int j)
{
    auto temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
void bubbleSort(vector<int> &nums)
{
    auto len = nums.size();
    for (int i = len - 1; i >= 0; i--) //需比较次数
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
                swap(nums, j, j + 1);
        }
    }
}

int main()
{
    vector<int> vi{4, 7, 2, 3, 5, 1, 8, 6};
    bubbleSort(vi);
    for (auto c : vi)
        cout << c << ' ';
}